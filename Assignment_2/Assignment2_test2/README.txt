//Ogabek Tulaev, jj0565yv
//CSIS 352-01

Assignment 2
==========================================================
This program creates a Min Heap by arranging the user inputs.



*User should enter "Yes", "No" or "quit" for certain 
situations, apart from entering heap elements.
*Program can handle wrong commands.



tulaev#.zip 
==========================================================
main.cpp
heapType.h
README.txt
makefile



How to Run:
==========================================================
1. Type "make" into the terminal while in /tulaev#/ to 
compile program.
2. Type "prog2" to run the program.
3. Enter an infix expression.	
4. Enter "make clean" to remove files created from compiling.

Example output:
==========================================================
"""""
Enter 'quit' to exit the program.

Is the heap empty? Yes
Enter a number, 0 to stop: 100
96
97
34
85
54
62
82
1
14
23
0
Numbers have been added to the heap. 
All elements in the heap: 
1 14 23 34 54 62 82 85 96 97 100 

The top of the heap is: 1
The length of the heap is: 11

Is the heap empty? No

Emtying the heap...1 14 23 34 54 62 82 85 96 97 100 
The Heap after pop(): 14 23 34 54 62 82 85 96 97 100 
Heap is emptied by destroy() function!

Is the heap empty? 
""""


Bugtesting
==========================================================
Please, let me know if you find any bugs.

jj0565yv@go.minnstate.edu


Others
==========================================================
The program is made in collaboration with Asadbek.
He mainly worked on main() function of the program.
