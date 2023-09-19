{-# OPTIONS -Wall #-}
module Program where

import Native ( jslog )
import Raylib
    ( initWindow,
      setTargetFPS,
      beginDrawing,
      endDrawing,
      clearBackground,
      getScreenHeight,
      drawFPS,
      drawText )

-- These are the haskell functions that will be called in JS
foreign export ccall startup :: IO ()

foreign export ccall mainLoop :: IO ()

foreign export ccall teardown :: IO ()

startup :: IO ()
startup = do
  initWindow 600 400 "raylib example - basic window"
  setTargetFPS 60
  height <- getScreenHeight
  jslog ("screen height: " ++ show height)
  return ()

mainLoop :: IO ()
mainLoop = do
  beginDrawing
  clearBackground 0xffd9b682 -- blue-ish color in hex in (a, b, g, r) form (this is a workaround to avoid having to implement the `Color` struct)
  drawFPS 10 10
  drawText "Hello from haskell!" 10 30 20 0xff000000
  endDrawing
  return ()

teardown :: IO ()
teardown = do
  return ()