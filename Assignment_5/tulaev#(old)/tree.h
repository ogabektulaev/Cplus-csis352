#ifndef H_Tree
#define H_Tree

#include <iostream>
using namespace std;

class AbstractNode {
	public:	
		virtual double eval() = 0;
		AbstractNode();
		virtual ~AbstractNode();
};

class LeafNode : public AbstractNode {
	private:
		double value;
	public:	
		LeafNode(double);
		~LeafNode();
		double eval();
};

class UnaryMinusNode : public AbstractNode {
	private:
		AbstractNode * child;
	public:
		UnaryMinusNode(AbstractNode *);
		~UnaryMinusNode();
		virtual double eval();
};

class BinaryNode : public AbstractNode{
	public:
		BinaryNode * left;
		BinaryNode * right;
		char op;

		BinaryNode(char, BinaryNode * = NULL, BinaryNode * = NULL);
		~BinaryNode();
		virtual double eval();
		char root();
		
};

#endif
