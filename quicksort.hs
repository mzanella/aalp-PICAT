quicksort [] = []
quicksort (x:xs) = 
	(quicksort [z | z <- xs, z <= x] ) ++ 
	[x] ++ 
	(quicksort [z | z <- xs, z > x] )