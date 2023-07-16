next :: Int -> Int
next n
    | (n `mod` 2 == 0) = (n `div` 2) 
    | otherwise = (3*n + 1)

stepv1 :: Int -> Int
stepv1 1 = 1
stepv1 x = stepv1 (next x)

stepv2 :: Int -> (Int,Int)
stepv2 x = step1 (x) 0 
    where
        step1 1 acc  = (1 ,acc)
        step1 x acc  = step1 (next x) (acc+1) 

stepv3 :: Int -> ([Int],Int)
stepv3 x = step1 (x) 0 []
    where
        step1 1 acc l = (l ,acc)
        step1 x acc l = step1 (next x) (acc+1) ((next x):l)


----------------------------------------------------------------
gcd1 :: Int -> Int -> Int
gcd1 a b
    | b == 0 = a
    | otherwise = gcd1 (b) (a `mod` b)



gcd2 :: Int -> Int -> (Int,Int)
gcd2 a b = gcd3 a b 0
    where
        gcd3 a 0 acc = (a,acc)
        gcd3 a b acc = gcd3 (b) (a `mod` b) (acc+1)
----------------------------------------------------------------

average :: Double -> Double -> Double
average x y = (x+y)/2

goodEnough :: Double -> Double -> Bool
goodEnough x g
    | abs(x - g*g) < 0.001 = True
    | otherwise = False  

improve :: Double -> Double -> Double
improve x y
    | goodEnough x y == True = y
    | otherwise = average y (x/y)

sqrtIter :: Double -> Double -> Double
sqrtIter x y
    | goodEnough x y = y
    | otherwise = sqrtIter x (improve x y) 
---------------------------------------------------------------

cubicIter :: Double -> Double -> Double
cubicIter x y = abs(((x/(y*y)) - 2*y)/3)

---------------------------------------------------------------

squaresum :: Int -> Int
squaresum x = sum [y*y | y <- [1..x]]

scalarProduct :: [Int] -> [Int] -> Int
scalarProduct x y = sum [x*y | (x,y) <- zip x y]