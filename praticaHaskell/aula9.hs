inRange :: Int -> Int -> [Int] -> [Int]
inRange _ _ [] = [] 
inRange a b (x:xs)
    | a == b = []
    | x > a && x < b = x : inRange a b xs
    | otherwise = inRange a b xs