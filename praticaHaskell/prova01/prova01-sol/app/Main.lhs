\begin{code}
module Main where

main :: IO ()
main = return ()

type Name = String
type Data = String

data Item
  = File Name Data
  | Dir Name [Item]
  deriving Eq

type FileSystem = [Item]

-- questão obter nome de um item do sistema de arquivos

name :: Item -> Name
name (File n _) = n
name (Dir n _) = n

type Path = Name

sep :: String
sep = "/"

-- listar diretórios

directories :: FileSystem -> [Item]
directories x
  = concatMap directories' x
    where
      directories' (File _ _) = []
      directories' d@(Dir _ subs) = d : directories subs

-- listar arquivos

files :: FileSystem -> [Item]
files
  = concatMap files'
    where
      files' f@(File _ _) = [f]
      files' (Dir _ subs) = files subs

-- consumo sistema de arquivos

totalSize :: FileSystem -> Int
totalSize = undefined

-- questão listar caminhos completos do sistema de arquivos.

paths :: FileSystem -> [Path]
paths = undefined

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

\end{code}



