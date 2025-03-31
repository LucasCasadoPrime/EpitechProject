data Item = Sword | Bow | MagicWand deriving (Eq)

instance Show Item where
    show Sword = "sword"
    show Bow = "bow"
    show MagicWand = "magic wand"

data Mob = Skeleton Item | Mummy | Witch (Maybe Item) deriving (Eq)

createMummy :: Mob
createMummy = Mummy

createArcher :: Mob
createArcher = Skeleton Bow

createKnight :: Mob
createKnight = Skeleton Sword

createWitch :: Mob
createWitch = Witch Nothing

createSorceress :: Mob
createSorceress = Witch (Just MagicWand)

create :: String -> Maybe Mob
create "mummy" = (Just createMummy)
create "doomed archer" = (Just createArcher)
create "dead knight" = (Just createKnight)
create "witch" = (Just createWitch)
create "sorceress" = (Just createSorceress)
create _ = Nothing

equip :: Item -> Mob -> Maybe Mob
equip _ Mummy = Nothing
equip nitem (Skeleton i) = Just (Skeleton nitem)
equip nitem (Witch (Just i)) = Just (Witch (Just nitem))

instance Show Mob where
    show Mummy = "mummy"
    show (Skeleton (Bow))= "doomed archer"
    show (Skeleton (Sword)) = "dead knight"
    show (Skeleton i) = "skeleton holding a " ++ show i
    show (Witch (Nothing)) = "witch"
    show (Witch (Just MagicWand))  = "sorceress"
    show (Witch i) = "witch holding a " ++ show i

class HasItem n where
    getItem  :: n -> Maybe Item
    hasItem :: n -> Bool
    hasItem _ = False

instance HasItem Mob where
    hasItem (Skeleton n) = True
    hasItem (Witch (Just n)) = True
    hasItem (Witch (Nothing)) = False
    getItem (Skeleton n) = Just n
    getItem (Witch (Just n)) = Just n
    getItem (Witch (Nothing)) = Nothing
