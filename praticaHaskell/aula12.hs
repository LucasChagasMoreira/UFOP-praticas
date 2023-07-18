data Arrombados altura = Xaider altura | Paulo altura | Panda altura

data Toy a b =
    Output b
    | Bell b
    | Done
    deriving (Show)

instance Functor (Toy a) where
    fmap f (Done) = Done
    fmap f (Bell b) = Bell (f b)
    fmap f (Output b) = Output (f b)  

instance Functor Arrombados where
    fmap f (Xaider b) = Xaider (f b)
    fmap f (Paulo b) = Paulo (f b)
    fmap f (Panda b) = Panda (f b)

data Tree a = Leaf a | Node a (Tree a) (Tree a)

instance Functor Tree where
    fmap f (Leaf a) = Leaf (f a)
    fmap f (Node x l r) = Node (f x) (fmap f l) (fmap f r)
