bools :: [Bool]
bools = [True,False,True]

nums :: [[Int]]
nums = [[1,23,3],[1,3,4]]

add :: Int -> Int -> Int -> Int
add x y z = x + y + z

copy :: a -> (a,a)
copy x = (x,x)

add1 :: Int -> Int
add1 x = x + 1

apply :: (a->b) -> [a] -> [b]
apply _ [] = []
apply f (x:xs)  = (f x) : apply f xs

swap :: (a,b) -> (b,a)
swap (x,y) = (y,x)

notboll:: [Bool] -> [Bool]
notboll [] = []
notboll (x:xs) = not x : notboll xs