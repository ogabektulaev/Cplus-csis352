#include <iostream>
#include "josephus.h"
#include "exceptions.h"
#include <list>
using namespace std;

//constructor
Josephus::Josephus(int n1, int k1, int s1) : n(n1), k(k1), s(s1) {
	if(n<=1)
		throw UniException("Number of people in the circle must be more than 1 !");
	else if(n>100)
		throw UniException("Sorry, we are not cruel enough to execute more than 100 people :(");
	else if(s<=0)
		throw UniException("Starting position must be greater than 0(zero) !");
	
	cout << "Circle size: " << n << endl;
	cout << "Starting at position " << s << endl;
	cout << "Every second person dies..." << endl;
} 

//member function 
int Josephus::findSurvivor(){
	// Initialize the list with n circle_of_people
    for (int i = 1; i <= n; i++) {
        circle_of_people.push_back(i);
    }
	
	//using random access iterator
	//"list<int> iterator:: current_target" doesn't work, so I used magical "auto":)
    auto current_target = circle_of_people.begin();
	
	for(int i = 1; i < s; i++)
		current_target++;

    while (circle_of_people.size() > 1) {
        for (int i = 1; i < k; i++) { //for loop to skip number of people based on k
            current_target++;
            if (current_target == circle_of_people.end()) { 
                current_target = circle_of_people.begin();
            }
        }

        current_target = circle_of_people.erase(current_target);

        if (current_target == circle_of_people.end()) {
            current_target = circle_of_people.begin();
        }
    }

    return circle_of_people.front();

}
