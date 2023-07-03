prodimpar :: [Int] -> Int
prodimpar [] = 1
prodimpar (x:xs)
    | x `mod` 2 == 0 = prodimpar xs
    | otherwise = x * prodimpar xs

prodimparv2 :: [Int] -> Int
prodimparv2 x = foldr (*) 1 (filter odd x)


allnats :: [Int] -> Bool
allnats [] = True
allnats (x:xs)
    | x > 0 = allnats xs
    | otherwise = False



pairs :: [a] -> [(a,a)]
pairs [] = []
pairs [x] = []
pairs (x:xs:xss) = (x,xs) : (pairs xss)


prova :: (Int,Int) -> [Int]
prova (x,y) = crial (x,y)
    where
        crial (a,b)
            | a <= 0 = []
            | otherwise = b : crial ((a-1,b))


uncompress :: [Int] -> [Int]
uncompress xs
    | allnats xs = foldr step [] listapronta
    | otherwise = []
    where
        listapronta = pairs xs
        step a acc = prova a ++ acc

