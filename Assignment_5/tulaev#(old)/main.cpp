//Name: Ogabek (jj0565yv)
//Due Date: 03.31.2023
//Class: CSIS 352
//Description: 


#include <iostream>
#include <cstring>
#include <stack>
#include "token.h"
#include "tree.h"

using namespace std;

bool isOperator(char c){
	if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(' || c == ')')
		return true;
	else
		return false;
}


BinaryNode* BuildTree(string expr){
	stack<BinaryNode*> s;
	BinaryNode *n, *n1;
	char c;
	int len = expr.length();

	for(int i=0; i<len; i++){
		c = expr[i];
		
		if(c == '+' || c == '-'){
			n = new BinaryNode(c, new BinaryNode(expr[i-1]), new BinaryNode(expr[i+1]));
			if(s.empty()){			
				s.push(n);
			}
			else{
				n1 = s.top();
				n -> left = n1;
				s.pop();
				s.push(n);
			}
		}
		else if( c == '*' || c == '/' ){
			n = new BinaryNode(c, new BinaryNode(expr[i-1]), new BinaryNode(expr[i+1]));
			if(s.empty()){			
				s.push(n);
			}
			else{
				n1 = s.top();
				n1->right = n;
				s.pop();
				s.push(n1);
			}
		}
	}
	return s.top();
}

void treePrinter(BinaryNode * root){
	if(root == nullptr)
		return;

	treePrinter(root->left);
	cout << root->eval() << " ";
	treePrinter(root->right);
}



int main() {
	

	string exp = "1+2*3-4/2";
	BinaryNode * result =  BuildTree(exp);
	treePrinter(result);
	
	return 0;
};
