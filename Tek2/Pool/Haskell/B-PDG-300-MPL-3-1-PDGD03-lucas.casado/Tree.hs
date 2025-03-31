data Tree a = Empty | Node (Tree a) a (Tree a) deriving Show

addInTree :: Ord a => a -> Tree a -> Tree a
addInTree a Empty = Node Empty a Empty
addInTree a (Node left val right) | a < val = Node (addInTree a left) val right
addInTree a (Node left val right) = Node left val (addInTree a right)

instance Functor Tree where
  fmap _ Empty = Empty
  fmap f (Node l a r) = Node (fmap f l) (f a) (fmap f r)