type Data = String
type Name = String

data Item 
    = File Name Data
    | Dir Name [Item]
    deriving Eq

type FileSystem = [Item] 

name :: Item -> Name
name (File x _) = x
name (Dir x _) = x

directories :: FileSystem -> [Item]
directories  = concatMap sla
    where
        sla (File _ _) = []
        sla (Dir x y) = (Dir x y) : directories y



files :: FileSystem -> [Item]
files = concatMap files'
    where
      files' f@(File _ _) = [f]
      files' (Dir _ subs) = files subs

root :: FileSystem
root = [
         Dir "Documents"
             [
               Dir "Texts"
                    [
                      File "teste.txt"
                           "12345"
                    , File "Foo.tex" "45678"
                    , File "bar.asc" ""
                    ]
             , Dir "Images" []
             , Dir "Thrash" []
             ]
       , Dir "Programs"
             [File "Sample.exe" "1010111101"]
       ]