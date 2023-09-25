//Ogabek Tulaev, jj0565yv
//CSIS 352-01
//Date: 04/30/2023

Assignment 6
==========================================================================
In this Assignment, I implemented Ternary Searching Algorithm
in 3 different ways, such as Recursive, Non-Recursive and 
another different variation.

Ternary Searching Algorithm is almost same  as the binary 
search. The difference is that, it reduces the time complexity 
a bit more. the algorithm involves ‘N’ steps. The searchable 
range would be the size = 3^N. Inversely, the number of steps 
needed to find the element is the log of the size of the collection. 
So the runtime is O(log N base 3).

The time complexity for ternary search is O (log N base 3 ) on average.

More information: https://www.geeksforgeeks.org/ternary-search/


*Please, input only integer. 

tulaev#.zip 
==========================================================================
main.cpp
ternarySearchNonRecursive.h
ternarySearchRecursive.h
ternarySearchThirdVariation.h
ternarySearchNonRecursive.cpp
ternarySearchRecursive.cpp
ternarySearchThirdVariation.cpp
README.txt
makefile



How to Run:
==========================================================
1. Type "make" into the terminal while in /tulaev#/ to 
compile program.
2. Type "prog6" to run the program.
3. Enter a number for searching.	
4. Enter "make clean" to remove files created from compiling.


Bugtesting
==========================================================
Please, let me know if you find any bugs.

jj0565yv@go.minnstate.edu


