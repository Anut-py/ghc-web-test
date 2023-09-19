{-# OPTIONS -Wall #-}
module Raylib (initWindow, setTargetFPS, beginDrawing, endDrawing, clearBackground, getScreenHeight, drawFPS, drawText) where

import Foreign (with)
import Foreign.C (CInt, CUInt, withCString)
import Native
  ( ParamType (SignedIntParam, UnsignedIntParam),
    callRaylibFunction,
    processParam,
  )

initWindow :: Int -> Int -> String -> IO ()
initWindow width height title =
  withCString
    title
    ( \t -> do
        wp <- processParam (fromIntegral width :: CInt) SignedIntParam
        hp <- processParam (fromIntegral height :: CInt) SignedIntParam
        tp <- processParam t UnsignedIntParam
        callRaylibFunction "_InitWindow_" [wp, hp, tp] 0
    )
setTargetFPS :: Int -> IO ()
setTargetFPS fps = do
  fp <- processParam (fromIntegral fps :: CInt) SignedIntParam
  callRaylibFunction "_SetTargetFPS_" [fp] 0

beginDrawing :: IO ()
beginDrawing = callRaylibFunction "_BeginDrawing_" [] 0

endDrawing :: IO ()
endDrawing = callRaylibFunction "_EndDrawing_" [] 0

clearBackground :: Integer -> IO ()
clearBackground color =
  with
    (fromIntegral color :: CUInt)
    ( \c -> do
        cp <- processParam c UnsignedIntParam
        callRaylibFunction "_ClearBackground_" [cp] 0
    )

getScreenHeight :: IO Int
getScreenHeight = callRaylibFunction "_GetScreenHeight_" [] 4

drawFPS :: Int -> Int -> IO ()
drawFPS x y = do
  xp <- processParam (fromIntegral x :: CInt) SignedIntParam
  yp <- processParam (fromIntegral y :: CInt) SignedIntParam
  callRaylibFunction "_DrawFPS_" [xp, yp] 0

drawText :: String -> Int -> Int -> Int -> Integer -> IO ()
drawText text x y size color =
  withCString
    text
    ( \t ->
        with
          (fromIntegral color :: CUInt)
          ( \c -> do
              tp <- processParam t UnsignedIntParam
              xp <- processParam (fromIntegral x :: CInt) SignedIntParam
              yp <- processParam (fromIntegral y :: CInt) SignedIntParam
              sp <- processParam (fromIntegral size :: CInt) SignedIntParam
              cp <- processParam c UnsignedIntParam
              callRaylibFunction "_DrawText_" [tp, xp, yp, sp, cp] 0
          )
    )
