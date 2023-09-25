#ifndef H_josephus
#define H_josephsProblem

#include <iostream>
#include <list>
using namespace std;


class Josephus{
	private:
		list<int> circle_of_people;
		int n, k, s;
	public:
		Josephus(int n, int k, int s);
		int findSurvivor();
};

#endif
