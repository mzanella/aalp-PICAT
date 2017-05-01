quicksort [] = []
quicksort (x:xs) = l ++ [x] ++ r
    where l = quicksort [z | z <- xs, z <= x]
          r = quicksort [z | z <- xs, z > x]