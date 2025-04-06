#include <iostream> // Includes the input-output stream library for console operations
#include <cmath>    // Includes the cmath library for mathematical functions like sqrt
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
 * Function to print the result of the jump search.
 * @param index - The index of the element, or -1 if not found.
 */
void printResult(int index) {
    if (index != -1) { // Checks if the element was found
        cout << "Element found at index: " << index << endl; // Prints the index of the found element
    } else {
        cout << "Element not found in the array." << endl; // Prints a message if the element was not found
    }
}

/**
 * Function to perform Jump Search on a sorted array.
 * @param arr - A constant reference to a vector of integers (sorted).
 * @param x - The integer value to search for.
 * @return The index of the element, or -1 if not found.
 */
int jumpSearch(const vector<int>& arr, int x) {
    int n = arr.size(); // Gets the size of the array
    if (n == 0) return -1; // Returns -1 if the array is empty

    int step = sqrt(n); // Calculates the block size to jump
    int prev = 0;       // Initializes the previous block's starting index

    // Finding the block where the element is present (if it exists)
    while (arr[min(step, n) - 1] < x) { // Checks the last element of the current block
        prev = step;                    // Updates the previous block's starting index
        step += sqrt(n);                // Moves to the next block
        if (prev >= n) {                // If the starting index exceeds the array size
            return -1;                  // Returns -1 as the element is not found
        }
    }

    // Performing a linear search within the identified block
    for (int i = prev; i < min(step, n); i++) { // Iterates through the block
        if (arr[i] == x) {                      // Checks if the current element matches the target
            return i;                           // Returns the index if the element is found
        }
    }

    return -1; // Returns -1 if the element is not found
}

/**
 * Main function to demonstrate Jump Search.
 */
int main() {
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // Initializes a sorted array of integers
    int x = 4; // Specifies the element to search for

    printInitialArray(arr); // Calls the function to print the initial array
    int result = jumpSearch(arr, x); // Calls the jump search function and stores the result
    printResult(result); // Calls the function to print the result of the search

    return 0; // Returns 0 to indicate successful program execution
}