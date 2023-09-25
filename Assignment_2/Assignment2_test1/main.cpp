#include <iostream>
#include "heapType.h"

using namespace std;

int main(){
	heapType <int> heap;
	int num;

	cout << "Enter a number, 0 to stop: ";
	cin >> num;
	
	while(num != 0){
		heap.insert(num);
		cin >> num;
	}	

	heap.dump();

	return 0;

}	
