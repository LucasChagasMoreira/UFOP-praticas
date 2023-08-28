import Parser

type Fuel = Int

type Distance = Int

type Position = (Int, Int)

data Robot =
    Robot {
        energy :: Fuel,
        distance :: Distance,
        current :: Position
    } deriving (Eq, Ord, Show)

data Instr =
    North
    | South
    | East
    | West
    | Collect
    | Recharge
    deriving (Eq, Ord)

instance Show Instr where
    show (North) = "North"
    show (South) = "South"
    show (East) = "East"
    show (West) = "West"    
    show (Collect) = "Collect"
    show (Recharge) = "Recharge"

data Program
    = Program {
        limit :: Position,
        init :: Position,
        instrs :: [Instr]
    } deriving (Eq, Ord ,Show)

positionParser :: Parser Char (Int,Int)
positionParser = tuplify <$> symbol '[' <*> natural <*> symbol ',' <*> natural <*> symbol ']'
    where
        tuplify _ x _ y _ = (x,y)

parserInstr :: Parser Char Instr
parserInstr = north <|> south <|> east <|> west <|> collect <|> recharge
    where 
        north = const North <$> symbol 'N'
        south = const South <$> symbol 'S'
        east = const East <$> symbol 'E'
        west = const West <$> symbol 'W'
        collect = const Collect <$> symbol 'C'
        recharge = const Recharge <$> symbol 'R'

exe :: Robot
exe = Robot {
        energy = 0,
        distance = 5,
        current = (0,0)
    }

parseProgram :: Parser Char Program
parseProgram = Program <$> positionParser <*> positionParser <*> greedy parserInstr

runRobot :: [Instr] -> Robot -> Robot
runRobot [] robo = robo
runRObot (North:xs) (Robot a b (c,d)) = runRobot xs (Robot (a-5) (b+1) (c,d+1))
runRObot (South:xs) (Robot a b (c,d)) = runRobot xs (Robot (a-5) (b+1) (c,d+1)) 
runRObot (East:xs) (Robot a b (c,d)) = runRobot xs (Robot (a-5) (b+1) (c,d+1)) 
runRObot (West:xs) (Robot a b (c,d)) = runRobot xs (Robot (a-5) (b+1) (c,d+1)) 
runRObot (Collect:xs) (Robot a b (c,d)) = runRobot xs (Robot (a-5) (b+1) (c,d+1)) 
runRObot (Recharge:xs) (Robot a b (c,d)) = runRobot xs (Robot (a-5) (b+1) (c,d+1)) 