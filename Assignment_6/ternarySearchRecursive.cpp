#include <iostream>
#include "ternarySearchRecursive.h"
using namespace std;

int ternarySearchRecursive(int arr[], int left, int right, int key) {
    if (right >= left) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (arr[mid1] == key)
            return mid1;

        if (arr[mid2] == key)
            return mid2;

        if (key < arr[mid1])
            return ternarySearchRecursive(arr, left, mid1 - 1, key);
        else if (key > arr[mid2])
            return ternarySearchRecursive(arr, mid2 + 1, right, key);
        else
            return ternarySearchRecursive(arr, mid1 + 1, mid2 - 1, key);
    }

    return -1;
}

