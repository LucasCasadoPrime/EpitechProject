import System.Environment
import Data.Char
import Data.List


data Listname = X | Y

type Doublelist = ([String], [String])

sa :: Doublelist -> Doublelist
sa ([], b) = ([], b)
sa (a:as, b) = (c:d:cs, b)
  where
    d = a
    last = drop 1 (a:as)
    (c : cs) = last

sb :: Doublelist -> Doublelist
sb (b, []) = (b, [])
sb (b, a : as) = (b, c : d : cs)
  where
    d = a
    last = drop 1 (a : as)
    (c : cs) = last

sc :: Doublelist -> Doublelist
sc a = sb (sa a)

pa :: Doublelist -> Doublelist
pa (a, []) = (a, [])
pa (a, b : bs) = (b:a, bs)

pb :: Doublelist -> Doublelist
pb ([], b) = ([], b)
pb (a : b, as) = (b, a : as)

ra :: Doublelist -> Doublelist
ra (a, []) = (a, [])
ra ([], b) = ([], b)
ra (la, lb) = (tail la ++ [head la], lb)

rb :: Doublelist -> Doublelist
rb ([], b) = ([], b)
rb (a, []) = (a, [])
rb (lb, la) = (lb, tail la ++ [head la])

rr :: Doublelist -> Doublelist
rr a = rb (ra a)

rra :: Doublelist -> Doublelist
rra (a, b) = (drop (length a -1) a ++ take (length a - 1) a, b)

rrb :: Doublelist -> Doublelist
rrb (a, b) = (a, drop (length b -1) b ++ take (length b - 1) b)

rrr :: Doublelist -> Doublelist
rrr a = rra (rrb a)

callFunction :: ([String], [String]) -> String -> ([String], [String])
callFunction (la, lb) "sa" = sa (la, lb) 
callFunction (la, lb) "sb" = sb (la, lb)
callFunction (la, lb) "sc" = sc (la, lb)
callFunction (la, lb) "pa" = pa (la, lb)
callFunction (la, lb) "pb" = pb (la, lb)
callFunction (la, lb) "ra" = ra (la, lb)
callFunction (la, lb) "rb" = rb (la, lb)
callFunction (la, lb) "rr" = rr (la, lb)
callFunction (la, lb) "rra" = rra (la, lb)
callFunction (la, lb) "rrb" = rrb (la, lb)
callFunction (la, lb) "rrr" = rrr (la, lb)

doFunction :: Doublelist -> [String] -> [String]
doFunction (la, _) [] = la
doFunction (la, lb) (f:fs) = doFunction (callFunction (la, lb) f) fs


isEqual :: Doublelist -> [String] -> IO ()
isEqual (la, lb) f
        | doFunction (la, lb) f == sort la = putStrLn "OK"
        | otherwise = putStrLn "KO"

main :: IO ()
main = do
        n <- getArgs
        f <- getLine
        let func = words f
        isEqual (n, []) func