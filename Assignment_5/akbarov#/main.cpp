//Name: Asadbek (sf9678zw)
//Due Date: 04.03.2023
//Class: CSIS 352
//Description: 

#include <iostream>
#include <stack>
#include "tree.h"
#include "polyTree.h"

using namespace std;

// Define the binary tree node structure




int main() {
    string infix, postfix;
    cout << "Enter infix expression: ";
    getline(cin, infix);
	try{
	postfix = infix2Postfix(infix);
	}
	catch(char c){
		cout << "[Exception] " << c << " is invalid input!" << endl;	
		return 0;
	}
    

    // Construct the binary tree and evaluate it
	cout << "Building a tree..." << endl;	
    TreeNode* root = constructTree(postfix);
    int result = evaluateTree(root);

    // Output the result
    cout << "Result: " << result << endl;

    return 0;
}
