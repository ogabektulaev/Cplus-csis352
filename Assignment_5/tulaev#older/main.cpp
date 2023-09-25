//Name: Ogabek (jj0565yv)
//Due Date: 03.31.2023
//Class: CSIS 352
//Description: 


#include <iostream>
#include <cstring>
#include <stack>

#include "tree.h"

using namespace std;

bool isOperator(char c){
	if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(' || c == ')')
		return true;
	else
		return false;
}


struct Node{
	char info;
	Node * llink;
	Node * rlink;
};

Node* createNode(char ch){
	Node* newNode = new Node();
	newNode -> info = ch;
	newNode -> llink = newNode->rlink = nullptr;
	return newNode;
}

Node* buildTree(string expr){
	stack<Node*> s;
	Node *n = new Node();
	Node *n1 = new Node();
	char c;
	int len = expr.length();

	for(int i=0; i<len; i++){
		c = expr[i];
		
		if(c == '+' || c == '-'){
			n = createNode(c);
			n->llink = LeafNode(expr[i-1]);
			n->rlink = LeafNode(expr[i+1]);
			//n = new BinaryNode(c, new BinaryNode(expr[i-1]), new BinaryNode(expr[i+1]));
			if(s.empty()){			
				s.push(n);
			}
			else{
				n1 = s.top();
				n -> llink = n1;
				s.pop();
				s.push(n);
			}
		}
		else if( c == '*' || c == '/' ){
			n = createNode(c);
			n->llink = LeafNode(expr[i-1]);
			n->rlink = LeafNode(expr[i+1]);
			if(s.empty()){			
				s.push(n);
			}
			else{
				n1 = s.top();
				n1->rlink = n;
				s.pop();
				s.push(n1);
			}
		}
	}
	return s.top(); 
}

void treePrinter(Node * root){
	if(root == nullptr)
		return;

	treePrinter(root->llink);
	cout << root->info << " ";
	treePrinter(root->rlink);
}



int main() {
	

	string exp = "1+2*3-4/2";
	Node * result =  buildTree(exp);
	treePrinter(result);
	
	return 0;
}
