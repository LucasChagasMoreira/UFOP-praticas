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

