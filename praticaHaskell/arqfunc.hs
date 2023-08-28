

abrearq :: String -> IO ()
abrearq path = do
    conteudo <- readFile path
    
    let qtdLinha = (countLines conteudo)
        qtdpalavras = (countWords conteudo)

    putStrLn $ "Linahs " ++ show qtdLinha
    putStrLn $ "palavras " ++ show qtdpalavras






countLines :: String -> Int
countLines x = length (lines x)

countWords :: String -> Int
countWords x = length (words x)