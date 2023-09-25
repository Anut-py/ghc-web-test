{-# OPTIONS -Wall #-}
module Raylib (initWindow, closeWindow, setTargetFPS, beginDrawing, endDrawing, clearBackground, getScreenHeight, drawFPS, drawText, isKeyDown, isMouseButtonPressed) where

import Foreign (with, toBool)
import Foreign.C (CInt, CUInt, withCString, CBool)
import Native (callRaylibFunction)

initWindow :: Int -> Int -> String -> IO ()
initWindow width height title =
  withCString
    title
    (callRaylibFunction "_InitWindow_" (fromIntegral width :: CInt) (fromIntegral height :: CInt))

closeWindow :: IO ()
closeWindow = callRaylibFunction "_CloseWindow_"

setTargetFPS :: Int -> IO ()
setTargetFPS fps = callRaylibFunction "_SetTargetFPS_" (fromIntegral fps :: CInt)

beginDrawing :: IO ()
beginDrawing = callRaylibFunction "_BeginDrawing_"

endDrawing :: IO ()
endDrawing = callRaylibFunction "_EndDrawing_"

clearBackground :: Integer -> IO ()
clearBackground color =
  with
    (fromIntegral color :: CUInt)
    (callRaylibFunction "_ClearBackground_")

getScreenHeight :: IO Int
getScreenHeight = fromIntegral <$> (callRaylibFunction "_GetScreenHeight_" :: IO CInt)

drawFPS :: Int -> Int -> IO ()
drawFPS x y = callRaylibFunction "_DrawFPS_" (fromIntegral x :: CInt) (fromIntegral y :: CInt)

drawText :: String -> Int -> Int -> Int -> Integer -> IO ()
drawText text x y size color =
  withCString
    text
    ( \t ->
        with
          (fromIntegral color :: CUInt)
          (callRaylibFunction "_DrawText_" t (fromIntegral x :: CInt) (fromIntegral y :: CInt) (fromIntegral size :: CInt))
    )

isKeyDown :: Int -> IO Bool
isKeyDown key = toBool <$> (callRaylibFunction "_IsKeyDown_" (fromIntegral key :: CInt) :: IO CBool)

isMouseButtonPressed :: Int -> IO Bool
isMouseButtonPressed button = toBool <$> (callRaylibFunction "_IsMouseButtonPressed_" (fromIntegral button :: CInt) :: IO CBool)
