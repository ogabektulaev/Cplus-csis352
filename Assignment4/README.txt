//Ogabek Tulaev, jj0565yv
//CSIS 352-01

Assignment 4
==========================================================
This program solves the Josephus problem.
STL, namespaces and exceptions are mainly used in this program



*User should enter number of people in the circle and starting position
*Program outputs the position of the survivor in the end



tulaev#.zip 
==========================================================
main.cpp
josephus.h
josephus.cpp
exceptions.h
README.txt
makefile



How to Run:
==========================================================
1. Type "make" into the terminal while in /tulaev#/ to 
compile program.
2. Type "prog4" to run the program.
3. Enter number of people in circle and starting position	
4. Enter "make clean" to remove files created from compiling.

Example output:
==========================================================
"""""
Enter the number of people: 6
Enter the position to start at: 3
Circle size: 6
Starting at position 3
Every second person dies...

[RESULT]: The survivor is at position 1
---------------------------------------------

Enter the number of people: 0
Enter the position to start at: 1

[EXCEPTION]: Number of people in the circle must be more than 1 !

---------------------------------------------

Enter the number of people: 101
Enter the position to start at: 1

[EXCEPTION]: Sorry, we are not cruel enough to execute more than 100 people :(

""""


Bugtesting
==========================================================
Please, let me know if you find any bugs.

jj0565yv@go.minnstate.edu


Others
==========================================================
The program is made in collaboration with Asadbek.
He mainly worked on exceptions.h 
