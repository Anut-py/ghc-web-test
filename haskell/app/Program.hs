{-# OPTIONS -Wall -Wno-unrecognised-pragmas #-}
{-# HLINT ignore "Use newtype instead of data" #-}
module Program (startup, mainLoop, shouldClose, teardown) where

import Native (jslog)
import Raylib
  ( beginDrawing,
    clearBackground,
    closeWindow,
    drawFPS,
    drawText,
    endDrawing,
    getScreenHeight,
    initWindow,
    setTargetFPS, isKeyDown, isMouseButtonPressed,
  )

data ProgramState = ProgramState {
  clicks :: Int
}

-- These are the main rendering functions of the program
startup :: IO ProgramState
startup = do
  initWindow 600 400 "raylib example - basic window"
  setTargetFPS 60
  height <- getScreenHeight
  jslog ("screen height: " ++ show height)
  jslog "Window initialized through Haskell"
  return $ ProgramState {
    clicks = 0
  }

mainLoop :: ProgramState -> IO ProgramState
mainLoop state = do
  pressed <- isMouseButtonPressed 0

  beginDrawing
  clearBackground 0xffd9b682 -- blue-ish color in hex in (a, b, g, r) form (this is a workaround to avoid having to implement the `Color` struct)
  drawFPS 10 10
  drawText "Hello from haskell!" 10 40 20 0xff000000
  drawText "Press [ESC] to close this" 10 70 20 0xff000000
  drawText ("This window has been clicked " ++ show (clicks state) ++ " times") 10 100 20 0xff000000
  endDrawing

  -- This will not show in the JS console. Usually printing to `stdout` would
  -- cause an error because browser_wasi_shim does not support stdout, but I
  -- used a patch to prevent it (see wasi_patch.ts and `poll_oneoff` in index.ts)
  putStrLn "test"

  return $ if pressed then state { clicks = clicks state + 1 } else state

shouldClose :: ProgramState -> IO Bool
shouldClose _ = isKeyDown 256

teardown :: ProgramState -> IO ()
teardown _ = do
  closeWindow
  jslog "Window closed through Haskell"
  return ()
