//Ogabek Tulaev, jj0565yv
//CSIS 352-01

Assignment 1 
==========================================================
This program takes infix expression via user input and
converts it to postfix expression and finds the result of 
the expression using stacks, queues and token class. 


*Please, avoid spaces in the input.
*The infix expression can consist of operands(double), 
arithmetic operators (^ * / % + -), and parentheses.
*The infix expression is entered on one line.



tulaev#.zip 
==========================================================
main.cpp
queueType.h
stackType.h
token.h
token.cpp
README.txt
makefile



How to Run:
==========================================================
1. Type "make" into the terminal while in /tulaev#/ to 
compile program.
2. Type "prog1" to run the program.
3. Enter an infix expression.	
4. Enter "make clean" to remove files created from compiling.

Example output:
==========================================================
"""""
Enter an Infix Expression: (4+8)/4-1 
The Postfix Expression: 4 8 + 4 / 1 - 
The Final Result: 2
""""


Bugtesting
==========================================================
Please, let me know if you find any bugs.

jj0565yv@go.minnstate.edu


Others
==========================================================
The program is made in collaboration with Asadbek.
He mainly worked on evaluation part of the program.
