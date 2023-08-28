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

data Tree a = Leaf a | Node a (Tree a) (Tree a) deriving Show

instance Functor Tree where
    fmap f (Leaf a) = Leaf (f a)
    fmap f (Node x l r) = Node (f x) (fmap f l) (fmap f r)

tree1 :: Tree Int
tree1 = Node 2 (Node 2 (Leaf 1) (Leaf 1))
               (Node 2 (Leaf 1) (Leaf 1))

-- Implementação do Applicative para a árvore
instance Applicative Tree where
    pure x = Leaf x
    (Leaf f) <*> (Leaf x) = Leaf (f x)
    (Leaf f) <*> (Node x left right) = Node (f x) (fmap f left) (fmap f right)
    (Node f leftF rightF) <*> (Leaf x) = Node (f x) (leftF <*> Leaf x) (rightF <*> Leaf x)
    (Node f leftF rightF) <*> (Node x leftX rightX) = Node (f x) (leftF <*> leftX) (rightF <*> rightX)
