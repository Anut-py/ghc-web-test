{-# OPTIONS -Wall #-}
module Native (ParamType (..), ProcessedParam (..), processParam, callRaylibFunction, jslog) where

import Foreign (Ptr, Storable (peek, poke, sizeOf), castPtr, free, malloc, mallocArray, pokeArray)
import Foreign.C (CChar, CString, CUChar (..), CUInt (..), castCharToCChar, withCStringLen)

-- These are the JS functions that will be used
foreign import ccall "main.h jslog" cjslog :: CString -> CUInt -> IO ()

foreign import ccall "main.h jsfree" jsfree :: Ptr () -> IO ()

foreign import ccall "main.h callRaylibFunction" ccallRaylibFunction :: CString -> CUInt -> Ptr (Ptr ()) -> Ptr CUInt -> Ptr CUChar -> CUInt -> CUInt -> IO (Ptr ())

data ParamType = SignedIntParam | UnsignedIntParam | FloatParam deriving (Enum)

data ProcessedParam = ProcessedParam (Ptr ()) Int Int

processParam :: (Storable a) => a -> ParamType -> IO ProcessedParam
processParam val pType = do
  ptr <- malloc
  poke ptr val
  return $ ProcessedParam (castPtr ptr) (sizeOf val) (fromEnum pType)

callRaylibFunction :: (Storable a) => String -> [ProcessedParam] -> Int -> IO a
callRaylibFunction func params returnSize = do
  let l = length func
      p = length params
  namePtr <- mallocArray l
  pokeArray namePtr (map castCharToCChar func :: [CChar])
  let nameLen = fromIntegral l :: CUInt
      ptrs = map (\(ProcessedParam ptr _ _) -> ptr) params
      sizes = map (\(ProcessedParam _ size _) -> fromIntegral size) params :: [CUInt]
      signs = map (\(ProcessedParam _ _ pType) -> fromIntegral pType) params :: [CUChar]
      numParams = fromIntegral p :: CUInt

  ptrsPtr <- mallocArray p
  pokeArray ptrsPtr ptrs

  sizesPtr <- mallocArray p
  pokeArray sizesPtr sizes

  typesPtr <- mallocArray p
  pokeArray typesPtr signs

  resPtr <- ccallRaylibFunction namePtr nameLen ptrsPtr sizesPtr typesPtr numParams (fromIntegral returnSize)
  res <- peek (castPtr resPtr)

  jsfree resPtr
  free namePtr
  free ptrsPtr
  mapM_ free ptrs
  free sizesPtr
  free typesPtr

  return res

jslog :: String -> IO ()
jslog str = withCStringLen str (\(s, len) -> cjslog s (fromIntegral len))
