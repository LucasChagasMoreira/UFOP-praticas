f :: Int -> Bool
f x 
  | x > 2 = True
  | otherwise = False

all1 :: (a -> Bool) -> [a] -> Bool
all1 _ [] = True
all1 f (x:xs) =  (f x) && (all1 f xs)

fall :: (a -> Bool) -> [a] -> Bool
fall f x = foldr func True x
  where
    func x acc
      | f x && acc = True
      | otherwise = False

akeWhile :: (a -> Bool) -> [a] ->[a]
akeWhile _ [] = []
akeWhile p (x : xs)
  | p x = x: takeWhile p xs
  | otherwise = []



fokeWhile :: (a -> Bool) -> [a] ->[a]
fokeWhile func list = foldr step [] list
  where
    step x y
      | func x && null y = [x]
      | func x = x : y
      | otherwise = []

concatmap2 :: (a -> [b]) -> [a] -> [b]
concatmap2 f x = concat(map f x)


concatmap3 :: (a -> [b]) -> [a] -> [b]
concatmap3 f x = foldr step [] x
  where
    step x xs =  f x ++ xs
{-
foldr :: (a -> b -> b) -> b -> [a] -> b
foldr _ v []       = v
foldr f v (x : xs) = x `f` foldr f v xs  
-}