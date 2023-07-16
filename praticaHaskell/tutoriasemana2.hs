--import Test.Tasty
--import Test.Tasty.HUnit
--import Test.Tasty.QuickCheck as QC
--
--main :: IO ()
--main = defaultMain tests


--1. (a)
inRangelist :: Int -> Int -> [Int] -> [Int]
inRangelist a b [] = []
inRangelist a b x = [y | y <- x , y > a && y < b]




inRange :: Int -> Int -> [Int] -> [Int]
inRange a b [] = []
inRange a b (x:xs)
    | x > a && x < b = x : inRange a b xs
    | otherwise = inRange a b xs


--2. (a)
countPositives :: [Int] -> Int
countPositives x = count x 0
    where
        count [] acc = acc
        count (x:xs) acc
            | x > 0 = count xs acc+1
            | otherwise = count xs acc