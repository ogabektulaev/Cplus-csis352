#include <iostream>
#include <vector>
#include "ternarySearchNonRecursive.h"
using namespace std;

int ternarySearchNonRecursive(int arr[], int n, int key) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (arr[mid1] == key)
            return mid1;

        if (arr[mid2] == key)
            return mid2;

        if (key < arr[mid1])
            right = mid1 - 1;
        else if (key > arr[mid2])
            left = mid2 + 1;
        else {
            left = mid1 + 1;
            right = mid2 - 1;
        }
    }

    return -1;
}


