fibas :: Int -> Int
fibas 0 = 0
fibas 1 = 1
fibas n = fibas (n-1) + fibas (n-2)