import Parser



data Bit = O|I deriving (Eq,Ord,Show)

data Field = Field{
    size :: Int,
    content :: [Bit]
} deriving(Eq,Ord,Show)



data UDP 
    = UDP {
        source :: Field,
        destination :: Field,
        plength :: Field,
        checksum :: Field,
        pdata :: [Field]

    } deriving (Eq, Ord,Show)



bitParser :: Parser Char Bit
bitParser = ((const O) <$> (symbol '0')) <|> ((const I) <$> (symbol '1'))

bitList :: Int -> Parser Char [Bit]
bitList 0 = succeed []
bitList n = (:) <$> bitParser <*> bitList (n-1)

fieldParser :: Int -> Parser Char Field
fieldParser n = Field n <$> bitList(n)

udpParser :: Parser Char UDP
udpParser = UDP <$> fieldParser 16 <*> fieldParser 16 <*> fieldParser 16 <*> fieldParser 16 <*> greedy (fieldParser 32)

func :: Parser Char [String]
func = parenthesized (listOf identifier (symbol ','))