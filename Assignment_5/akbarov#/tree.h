#pragma once
#include<iostream>
using namespace std;
#include <stack>

struct TreeNode {
    char data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char c) : data(c), left(NULL), right(NULL) {}
};

// Define a function to check if a character is an operator
bool isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}

// Define a function to construct the binary tree
TreeNode* constructTree(string postfix) {
    stack<TreeNode*> st;

    for (int i = 0; i < postfix.length(); i++) {
        char c = postfix[i];

        if (isdigit(c)) {
            TreeNode* node = new TreeNode(c);
            st.push(node);
        }
        else if (isOperator(c)) {
            TreeNode* node = new TreeNode(c);
            node->right = st.top();
            st.pop();
            node->left = st.top();
            st.pop();
            st.push(node);
        }
    }

    return st.top();
}

// Define a function to evaluate the binary tree
int evaluateTree(TreeNode* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return root->data - '0';

    int leftVal = evaluateTree(root->left);
    int rightVal = evaluateTree(root->right);

    if (root->data == '+')
        return leftVal + rightVal;
    else if (root->data == '-')
        return leftVal - rightVal;
    else if (root->data == '*')
        return leftVal * rightVal;
    else if (root->data == '/')
        return leftVal / rightVal;
}


string infix2Postfix(string infix){
	// Convert infix to postfix
    stack<char> st;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
		int j = c; //getting ascii value of character to check input 
		if(j>=40 && j<=57){
		    if (isalnum(c))
		        postfix += c;
		    else if (c == '(')
		        st.push(c);
		    else if (c == ')') {
		        while (!st.empty() && st.top() != '(') {
		            postfix += st.top();
		            st.pop();
		        }
		        if (!st.empty())
		            st.pop();
		    }
		    else {
		        while (!st.empty() && st.top() != '(' && (c == '+' || c == '-' || c == '*' || c == '/') && (st.top() == '*' || st.top() == '/')) {
		            postfix += st.top();
		            st.pop();
		        }
				st.push(c);
			}
		}
		else{
			throw c; //throwing exception for invalid input
		}             
    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }
	//cout << postfix << endl;
	return postfix;
	
}
