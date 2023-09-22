{-# OPTIONS -Wall #-}
{-# LANGUAGE ConstrainedClassMethods #-}

module Processable (ProcessedParam (..), ParamType (..), Processable (..)) where

import Foreign (Ptr, Storable (poke, sizeOf), castPtr, malloc)
import Foreign.C (CChar, CFloat, CInt, CUChar, CUInt, CBool)

data ParamType = SignedIntParam | UnsignedIntParam | FloatParam | VoidParam deriving (Enum)

data ProcessedParam = ProcessedParam (Ptr ()) Int Int

class Processable a where
  processableType :: a -> ParamType

  processParam :: (Storable a) => a -> IO ProcessedParam
  processParam val = processParamRaw val $ processableType val

instance Processable (Ptr a) where
  processableType _ = UnsignedIntParam

instance Processable CInt where
  processableType _ = SignedIntParam

instance Processable CUInt where
  processableType _ = UnsignedIntParam

instance Processable CChar where
  processableType _ = SignedIntParam

instance Processable CUChar where
  processableType _ = UnsignedIntParam

instance Processable CFloat where
  processableType _ = FloatParam

instance Processable CBool where
  processableType _ = UnsignedIntParam

instance Processable () where
  processableType _ = VoidParam

processParamRaw :: (Storable a) => a -> ParamType -> IO ProcessedParam
processParamRaw val pType = do
  ptr <- malloc
  poke ptr val
  return $ ProcessedParam (castPtr ptr) (sizeOf val) (fromEnum pType)
