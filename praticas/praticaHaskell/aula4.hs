incAll :: [Int] -> [Int]
incAll xs = [x + 1 | x <- xs]

minList :: [Int] -> Int
minList [x] = x
minList (x:xs) = min x (minList xs)
minList [] = error "Lista vazia"

andbool :: [Bool] -> Bool
andbool [] = True
andbool (x:xs) = x && andbool xs

orbool :: [Bool] -> Bool
orbool [] = False
orbool (x:xs) = x || orbool xs

indexof :: Int -> [Int] -> Int
indexof x y = index x y 0
    where
        index _ [] _ = -1
        index x (y:ys) ac
            | x == y = ac
            | otherwise = index x ys (1+ac) 


removeall :: Int -> [Int] -> [Int]
removeall x y = [z | z <- y , z /= x]