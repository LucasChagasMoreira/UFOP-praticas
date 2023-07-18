guess :: String -> Int -> IO ()
guess valorcorreto pontos = do
    tentas <- getLine

    if tentas == valorcorreto  then
        putStrLn ("Acertou, Qtd pontos: " ++ show pontos)
        
    else if (tentas < valorcorreto) then do
        putStrLn "menor"
        guess valorcorreto (pontos-100)

    else do
        putStrLn "maior"
        guess valorcorreto (pontos-100)

