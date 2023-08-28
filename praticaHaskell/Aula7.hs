{-# LANGUAGE StandaloneDeriving #-}
module Aula07 where

import Prelude hiding (Maybe, Nothing, Just)
import Data.Maybe

data Point = Point Float Float

deriving instance Show Point
deriving instance Show Shape

data Shape
   = Retangulo Point Float Float
   | Circulo Point Float
   | Triangulo Point Point Point

dist :: (Point, Point) -> Float
dist ((Point x1 y1), (Point x2 y2)) =
  sqrt (x11 * x11 + y11 * y11)
   where
     x11 = x1 - x2
     y11 = y1 - y2

perimetro :: Shape -> Float
perimetro (Retangulo _ w h) = 2 * w + 2 * h
perimetro (Circulo _ r) = 2 * pi * r
perimetro (Triangulo a b c) = dist (a,b) + dist (b,c) + dist (c,a)

area :: Shape -> Float
area (Retangulo _ w h) =  w * h
area (Circulo _ r) = pi * r*r

data IntTree = ILeaf | INode Int IntTree IntTree

folhas :: IntTree -> Int
folhas ILeaf = 1
folhas (INode _ l r) = (folhas l) + (folhas r)

elementos :: IntTree -> Int
elementos ILeaf = 1
elementos (INode _ l r) = 1+(elementos l) + (elementos r)

exemploArvore :: IntTree
exemploArvore =
  INode 1
    (INode 2
      (INode 3 ILeaf ILeaf)
      (INode 4 ILeaf ILeaf)
    )
    (INode 5
      (INode 6 ILeaf ILeaf)
      (INode 7 ILeaf ILeaf)
    )

main :: IO ()
main = do
  let numFolhas = folhas exemploArvore
  putStrLn $ "Número de folhas: " ++ show numFolhas