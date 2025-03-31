myElem :: (Eq a) => a -> [a] -> Bool
myElem _ [] = False
myElem n (a:as)
    | n == a = True
    |otherwise = myElem n as

safeDiv :: Int -> Int -> Maybe Int
safeDiv a b  
    | b == 0 = Nothing
    | otherwise = Just (div a b)

safeNth :: [a] -> Int -> Maybe a
safeNth [] b = Nothing
safeNth a b = if b == 0 then Just(head a) else safeNth (tail(a)) (b-1)


safeSucc :: Maybe Int -> Maybe Int
safeSucc Nothing = Nothing
safeSucc (Just x) = Just (x + 1)

myLookup :: Eq a => a -> [( a , b ) ] -> Maybe b
myLookup _ [] = Nothing
myLookup b (a:as)
    | b /= fst(a) = myLookup b as
    | b == fst(a) = Just (snd(a))

maybeDo :: ( a -> b -> c ) -> Maybe a -> Maybe b -> Maybe c
maybeDo f _ Nothing = Nothing
maybeDo f Nothing _ = Nothing
maybeDo f (Just a) (Just b) = f <$> Just (a) <*> Just (b)


getLineLength :: IO Int
getLineLength = do x <- getLine 
                   return (length x)

printAndGetLength :: String -> IO Int
printAndGetLength s = putStrLn s >> return (length s)

concatLines :: Int -> IO String
concatLines i | i <= 0  = return []
concatLines i = do x <- getLine
                   xs <- concatLines (i-1)
                   return (x ++ xs)
