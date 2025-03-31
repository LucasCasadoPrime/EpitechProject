mySucc :: Int -> Int
mySucc x = x + 1

myIsNeg :: Int -> Bool
myIsNeg n = if n < 0 then True else False

myAbs :: Int -> Int
myAbs n = if n < 0 then n + (2 * (-n)) else n

myMin :: Int -> Int -> Int
myMin x y = if x < y then x else y

myMax :: Int -> Int -> Int
myMax x y = if x > y then x else y

myTuple :: a -> b -> (a , b)
myTuple a b = (,) a  b

myTruple :: a -> b -> c -> (a , b , c )
myTruple a b c =  (,,) a  b c

myFst :: (a , b) -> a
myFst (a, b) = a

mySnd :: (a , b) -> b
mySnd (a, b) = b

mySwap :: (a , b ) -> (b , a )
mySwap (a, b) = (b, a)

myHead :: [a] -> a
myHead [] = error "Empty list"
myHead (a:b) = a

myTail :: [a] -> [a]
myTail [] = error "Empty list"
myTail (a : b) = b

myLength :: [a] -> Int
myLength [] = 0
myLength (a:as) = 1 + myLength as

myNth :: [a] -> Int -> a
myNth a n
    | n > myLength a = error "Index too large"
    | n < 0 = error "Index Negative"
    | otherwise = if n == 0 then myHead a else myNth (myTail(a)) (n-1)

myTake :: Int -> [a] -> [a]
myTake n (a:as)
    | n > myLength as = as
    | n < 0 = error "Index negtive"
    | n == 0 = []
    | otherwise = a : myTake (n-1) as

myDrop :: Int -> [a] -> [a]
myDrop n as
    | n > myLength as = []
    | n < 0 = error "Index negtive"
    | n == 0 = as
    | otherwise = myDrop (n-1) (myTail as)

myAppend :: [a] -> [a] -> [a]
myAppend [] b = b
myAppend (a:as) b = a : myAppend as b

myReverse :: [a] -> [a]
myReverse [] = []
myReverse (a:as) = myAppend (myReverse as) [a]

myInit :: [a] -> [a]
myInit [] = error "Empty list"
myInit a = myReverse (myTail (myReverse (a)))

myLast :: [a] -> a
myLast (a:[]) = a
myLast (a:b) = myLast b

myZip :: [a] -> [b] -> [(a, b)]
myZip a [] = error "ERROR"
myZip [] b = error "ERROR"
myZip (a:as) (b:bs) = (a, b):myZip as bs

myUnzip :: [(a,b)] -> ([a],[b])
