module Main where

import System.Environment (getArgs)

main :: IO ()
main = do
  -- Obter o nome do arquivo a partir dos argumentos de linha de comando
  args <- getArgs
  case args of
    [filename] -> do
      -- Ler o conteúdo do arquivo
      content <- readFile filename
      -- Calcular as estatísticas
      let numLines = countLines content
          numWords = countWords content
      -- Imprimir as estatísticas
      putStrLn $ "Número de linhas: " ++ show numLines
      putStrLn $ "Número de palavras: " ++ show numWords
    _ -> putStrLn "Por favor, forneça o nome de um arquivo como argumento."

-- Função para contar o número de linhas em uma string
countLines :: String -> Int
countLines = length . lines

-- Função para contar o número de palavras em uma string
countWords :: String -> Int
countWords = length . words