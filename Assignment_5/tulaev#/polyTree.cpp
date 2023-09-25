#include <iostream>
#include "tree.h"
using namespace std;


double AbstractNode:: eval(){return 0;};
AbstractNode::AbstractNode() {};
AbstractNode:: ~AbstractNode() {};


LeafNode::LeafNode(double d) : value(d) {};
LeafNode::~LeafNode() {};
double LeafNode:: eval() {return value;};


UnaryMinusNode::UnaryMinusNode(AbstractNode * c) : child(c) {};
UnaryMinusNode::~UnaryMinusNode() {delete child;};
double UnaryMinusNode::  eval() {return ((-1.0)*child->eval());};


BinaryNode :: BinaryNode(char o, AbstractNode * l,AbstractNode * r) : left(l), right(r), op(o) {};
BinaryNode :: ~BinaryNode() {delete left; delete right;};

double BinaryNode ::  eval() {
			switch(op) {
				case '+':
					return left->eval()+right->eval();
				case '-':
					return left->eval()-right->eval();
				case '*':
					return left->eval()*right->eval();
				case '/':
					return left->eval()/right->eval();
				default:
					return 0;
			};
		};




