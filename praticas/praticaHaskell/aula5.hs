import Data.Char

capitalize :: String -> String
capitalize [] = []
capitalize y = map toUpper y


withoutPrimes :: [Int] -> [Int]
withoutPrimes [] = []
withoutPrimes list = filter isprime list
    where
        isprime n
            | n <= 1 = True
            | otherwise = vai 2
            where
                vai divisor
                    | divisor * divisor > n = False
                    | mod n divisor == 0 = True
                    | otherwise = vai (divisor+1)
            
