//Name: Ogabek (jj0565yv)
//Due Date: 04.30.2023
//Class: CSIS 352

#include <iostream>
#include <vector>
#include "ternarySearchNonRecursive.h"
#include "ternarySearchRecursive.h"
#include "ternarySearchThirdVariation.h"

using namespace std;


int main() {
    int arr[] = {1, 4, 7, 10, 13, 16, 19, 22, 25, 28}; 
    int n = sizeof(arr) / sizeof(arr[0]);  //length of the array
    int key; //item to be searched
	
	cout << "Elements of array: [";
	for(int i = 0; i<n; i++){
		if(i+1 == n)
			cout << arr[i] << "]" << endl;
		else
			cout << arr[i] << ", ";
	}

	cout << "Enter the number for searching: ";
	cin >> key;
	
    int result = ternarySearchRecursive(arr, 0, n - 1, key);

    if (result == -1)
        cout << "[REC] Element not found." << endl;
    else
        cout << "[REC] Element found at index " << result << "." << endl;


    int result2 = ternarySearchNonRecursive(arr, n, key);

    if (result2 == -1)
        cout << "[NONREC] Element not found." << endl;
    else
        cout << "[NONREC] Element found at index " << result2 << "." << endl;


    int result3 = ternarySearchThirdVariation(arr, n, key);

    if (result3 == -1)
        cout << "[THIRDVAR] Element not found." << endl;
    else
        cout << "[THIRDVAR] Element found at index " << result3 << "." << endl;


    return 0;
}
