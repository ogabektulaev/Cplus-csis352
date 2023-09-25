//Name: Ogabek (jj0565yv)
//Due Date: 02.06.2023
//Class: CSIS 352
//Description: The program takes infix expression via user input, converts it to the postfix expression and calculates result.


#include <iostream>
#include <cstring>

#include "token.h"
#include "queueType.h"
#include "stackType.h"

using namespace std;

int main(){
   string input; //string variable to store user's input

   stackType <Token>stack; 
   queueType <Token>q;	
   Token t;
   Token oper;	

   cout << "Enter an Infix Expression: ";
   cin >> input; //storing the user's input as string (I also know how to receive it directly as token by using while loop :)
   int n = input.length();

   for(int i = 0; i<n; i++){  
	
	char element = input[i]; //addressing each element of the string 
	if(isdigit(element)){  //this if else statement is for identifying digit(can be multiple digit) and storing it to the Queue
		int val=0;
		while(i<n && isdigit(input[i])){
			val = val*10 + int(input[i]-'0');  //making multiple digit int from char by addressing the string elements one by one
			i++;			
		}
		t = val; //assigning operand to the token	
		i--; 
		q.addQueue(t);	
	}
	else{ //dealing with operators
		t = input[i];
				
		if (t.Valid())
		{  	
			if (t.IsOperator()){
				if(stack.isEmptyStack() || !stack.top().IsOperator())		 
					stack.push(t);   
				else{
					while(!stack.isEmptyStack() && t.Precedence() <= stack.top().Precedence()){ //managing the operators by considering precedences 				
					q.addQueue(stack.top());  
					stack.pop();
					}
					stack.push(t);
				}
			}
			else if (t.IsLeftParen()){
				stack.push(t);
			}
		 	else if (t.IsRightParen()){
				oper = stack.top(); 
				q.addQueue(oper);
				stack.pop();
				stack.pop();
			}
	   	}
	   	else
		 	cout << "not a valid token\n";
	}
}

//making postfix ready 
   while(!stack.isEmptyStack()){ 
	q.addQueue(stack.top()); 
	stack.pop();
	}
   q.printQueue();  //new printing method is added to the queueType.h

//evaluating part   
   Token operand1, operand2, oper1, universal; //declaring required variables
   Token result = 0; 
   while (!q.isEmptyQueue()){ 
	universal = q.front(); //addressing the queue elements from left to right
	q.deleteQueue();	//removing the first element from queue
	
	if(universal.IsOperand())
		stack.push(universal); //pushing the operands to the stack
	else if(universal.IsOperator()){
		//getting the operands of the stack and removing them
		operand1 = stack.top(); 
		stack.pop();
		operand2 = stack.top();
		stack.pop();
		
		//checking the operators and evaluating accordingly (I could have used switch case statements)
		if(universal.Operator() == '+'){ 
			result = operand1 + operand2;
			stack.push(result);  //keeping the result as operand every time, so in the end we will have only result in the stack
		}
		else if(universal.Operator() == '-'){
			result = operand2 - operand1;
			stack.push(result);
		}
		else if(universal.Operator() == '*'){
			result = operand1 * operand2;
			stack.push(result);
		}
		else if(universal.Operator() == '/'){
			result = operand2 / operand1;
			stack.push(result);
		}
		else if(universal.Operator() == '^'){
			result = operand2^operand1;
			stack.push(result);
		}
	}
   }

   cout << "The Final Result: " << result << endl; // printing the result
   return 0;
}
