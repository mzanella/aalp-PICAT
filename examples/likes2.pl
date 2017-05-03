likes(mary, X) :- reptile(X), !, fail.
likes(mary, X) :- animal(X).

animal(coccodrillo).
animal(vipera).
animal(cane).
animal(cavallo).

reptile(coccodrillo).
reptile(vipera).
