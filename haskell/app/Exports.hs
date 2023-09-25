{-# OPTIONS -Wall #-}

module Exports (startup, mainLoop, shouldClose, teardown) where

import Foreign (Ptr, castPtrToStablePtr, castStablePtrToPtr, deRefStablePtr, freeStablePtr, newStablePtr)
import qualified Program as P

-- These are the actual haskell functions that will be called in JS
-- See Program.hs for the rendering functions
foreign export ccall startup :: IO (Ptr ())

startup :: IO (Ptr ())
startup = P.startup >>= createStablePtr

foreign export ccall mainLoop :: Ptr () -> IO (Ptr ())

mainLoop :: Ptr () -> IO (Ptr ())
mainLoop ptr = popStablePtr ptr >>= P.mainLoop >>= createStablePtr

foreign export ccall shouldClose :: Ptr () -> IO Bool

shouldClose :: Ptr () -> IO Bool
shouldClose ptr = readStablePtr ptr >>= P.shouldClose

foreign export ccall teardown :: Ptr () -> IO ()

teardown :: Ptr () -> IO ()
teardown ptr = popStablePtr ptr >>= P.teardown

-- Convenience functions for dealing with `StablePtr`s
createStablePtr :: a -> IO (Ptr ())
createStablePtr val = castStablePtrToPtr <$> newStablePtr val

readStablePtr :: Ptr () -> IO a
readStablePtr ptr = deRefStablePtr $ castPtrToStablePtr ptr

popStablePtr :: Ptr () -> IO a
popStablePtr ptr = do
  let sptr = castPtrToStablePtr ptr
  val <- deRefStablePtr sptr
  freeStablePtr sptr
  return val
