#include <iostream> // Includes the input-output stream library for console operations
#include <vector>   // Includes the vector library for using the vector container

using namespace std; // Allows usage of standard library functions without prefixing with std::

/**
 * Function to print the initial array to the console.
 * @param arr - A constant reference to a vector of integers.
 */
void printInitialArray(const vector<int>& arr) {
    cout << "Initial array: "; // Prints a label for the array
    for (int num : arr) {      // Iterates through each element in the vector
        cout << num << " ";    // Prints each element followed by a space
    }
    cout << endl;              // Ends the line after printing all elements
}

/**
 * Function to print the result of the binary search.
 * @param index - The index of the target element, or -1 if not found.
 */
void printResult(int index) {
    if (index != -1) { // Checks if the target element was found
        cout << "Element found at index: " << index << endl; // Prints the index of the found element
    } else {
        cout << "Element not found in the array." << endl; // Prints a message if the element was not found
    }
}

/**
 * Function to perform binary search on a sorted array.
 * @param arr - A constant reference to a vector of integers (sorted).
 * @param target - The integer value to search for.
 * @return The index of the target element, or -1 if not found.
 */
int binarySearch(const vector<int>& arr, int target) {
    int left = 0;                // Initializes the left boundary of the search range
    int right = arr.size() - 1;  // Initializes the right boundary of the search range

    while (left <= right) {      // Continues searching while the range is valid
        int mid = left + (right - left) / 2; // Calculates the middle index to avoid overflow

        if (arr[mid] == target) { // Checks if the middle element is the target
            return mid;           // Returns the index if the target is found
        } else if (arr[mid] < target) { // Checks if the target is greater than the middle element
            left = mid + 1;       // Narrows the search range to the right half
        } else {                  // If the target is less than the middle element
            right = mid - 1;      // Narrows the search range to the left half
        }
    }

    return -1; // Returns -1 if the target is not found in the array
}

/**
 * Main function to demonstrate binary search.
 */
int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19}; // Initializes a sorted array of integers
    int target = 7; // Specifies the target element to search for

    printInitialArray(arr); // Calls the function to print the initial array
    int result = binarySearch(arr, target); // Calls the binary search function and stores the result
    printResult(result); // Calls the function to print the result of the search

    return 0; // Returns 0 to indicate successful program execution
}