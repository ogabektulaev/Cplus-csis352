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
		AbstractNode * left;
		AbstractNode * right;
		char op;

		BinaryNode(char, AbstractNode * = NULL, AbstractNode * = NULL);
		~BinaryNode();
		virtual double eval();
		
};

#endif
