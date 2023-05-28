import Prelude hiding ( replicate , null )

xor :: (Bool,Bool) -> Bool
xor (x,y) 
    | (x,y) == (True,False) = True
    | (x,y) == (False,True) = True
    | otherwise = False


x1 :: [Int] -> Bool
x1 [] = False
x1 (x:xs) 
    | x > 0 = True
    | otherwise = nsei xs
    