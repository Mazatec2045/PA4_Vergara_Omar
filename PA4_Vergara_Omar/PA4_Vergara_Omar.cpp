#include <iostream>

using namespace std;

// Constants – Things that won't change
const int ARRAY_SIZE = 20;
const int TARGET_VALUE = 521;

// Function Prototypes (Promises of functions we'll write later)
int linearSearch(const int arr[], int size, int target);
int binarySearch(const int arr[], int size, int target);

int main() {
    // Our sorted number list (Binary search needs this!)
    int numbers[ARRAY_SIZE] = { 101, 142, 147, 189, 199, 207, 222, 234, 289, 296, 310, 319, 388, 394, 417, 429, 447, 521, 536, 600 };

    //LINEAR SEARCH
    int linearPosition = linearSearch(numbers, ARRAY_SIZE, TARGET_VALUE);
    if (linearPosition != -1) {
        cout << "Target found (linear search) at index: " << linearPosition << endl;
    }
    else {
        cout << "Target not found (linear search)." << endl;
    }

    // BINARY SEARCH
    int binaryPosition = binarySearch(numbers, ARRAY_SIZE, TARGET_VALUE);
    if (binaryPosition != -1) {
        cout << "Target found (binary search) at index: " << binaryPosition << endl;
    }
    else {
        cout << "Target not found (binary search)." << endl;
    }

    return 0;
}

// Linear Search: The slowpoke search
int linearSearch(const int arr[], int size, int target) {
    int comparisons = 0;

    for (int i = 0; i < size; i++) {
        comparisons++;
        if (arr[i] == target) {
            cout << "Linear search comparisons: " << comparisons << endl;
            return i; // Found it! Tell where it is (the index)
        }
    }
    cout << "Linear search comparisons: " << comparisons << endl;
    return -1; // Not found 
}

// Binary Search: The smart search
int binarySearch(const int arr[], int size, int target) {
    int comparisons = 0;
    int left = 0;     // Start of our search area
    int right = size - 1; // End of our search area

    while (left <= right) {
        comparisons++;
        int middle = left + (right - left) / 2;  // Find the middle point

        if (arr[middle] == target) { // Did we hit the jackpot?
            cout << "Binary search comparisons: " << comparisons << endl;
            return middle;  // Found it! Tell where it is (the index)
        }
        else if (arr[middle] < target) {  // Too low, search the upper half
            left = middle + 1;
        }
        else { // Too high,  search the lower half
            right = middle - 1;
        }
    }
    cout << "Binary search comparisons: " << comparisons << endl;
    return -1; // Not found 
}
