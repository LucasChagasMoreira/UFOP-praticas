data Arrombados altura = Xaider altura | Paulo altura | Panda altura

data Toy b =
    Output b
    | Bell b
    | Done
    deriving (Show)

instance Functor Toy where
    fmap f (Done) = Done
    fmap f (Bell b) = Bell (f b)
    fmap f (Output b) = Output (f b)  

instance Functor Arrombados where
    fmap f (Xaider b) = Xaider (f b)
    fmap f (Paulo b) = Paulo (f b)
    fmap f (Panda b) = Panda (f b)

instance Applicative Arrombados where
    pure = Arrombados a
    Xaider f <*> (Xaider a) = Xaider (f a)
    Paulo f <*> (Paulo a) = Paulo (f a)
    Panda f <*> (Panda a) = Panda (f a)