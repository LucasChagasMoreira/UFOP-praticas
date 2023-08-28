{-# LANGUAGE InstanceSigs #-}

data Vec3 = Vec3 Int Int Int

--instance Eq Vec3 where
--    (Vec3 x y z) == (Vec3 a b c) = (x == a) && (y == b) && (z == c)
--    (x) /= (y) = not (x == y)

instance Eq Vec3 where
    (==) :: Vec3 -> Vec3 -> Bool
    (Vec3 x y z) == (Vec3 a b c) = (x == a) && (y == b) && (z == c) 
    (/=) :: Vec3 -> Vec3 -> Bool
    (x) /= (y) = not (x == y)



data Person = Person {name :: String, age :: Int}

stringigual :: String -> String -> Bool
stringigual [] [y] = False
stringigual [x] [] = False
stringigual [] [] = True
stringigual (x:xs) (y:ys)
    | x == y = stringigual xs ys
    | otherwise = False


instance Eq Person where
    (==) :: Person -> Person -> Bool
    (Person nm _) == (Person mn _) = stringigual nm mn
    (/=) :: Person -> Person -> Bool
    (x) /= (y) = not (x == y)



instance Show Person where
    show (Person nome idade) = "Nome: " ++ nome ++ ", " ++ "Idade: " ++ show idade