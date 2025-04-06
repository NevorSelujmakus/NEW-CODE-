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
 * Function to print the result of the interpolation search.
 * @param index - The index of the key element, or -1 if not found.
 * @param key - The value of the element being searched for.
 */
void printResult(int index, int key) {
    if (index != -1) { // Checks if the key element was found
        cout << "Element " << key << " found at index " << index << endl; // Prints the index of the found element
    } else {
        cout << "Element " << key << " not found in the array" << endl; // Prints a message if the element was not found
    }
}

/**
 * Function to perform interpolation search on a sorted array.
 * @param arr - A constant reference to a vector of integers (sorted).
 * @param key - The integer value to search for.
 * @return The index of the key element, or -1 if not found.
 */
int interpolationSearch(const vector<int>& arr, int key) {
    int low = 0;                // Initializes the lower boundary of the search range
    int high = arr.size() - 1;  // Initializes the upper boundary of the search range

    // Continues searching while the range is valid and the key is within the range
    while (low <= high && key >= arr[low] && key <= arr[high]) {
        // If the array has only one element
        if (low == high) {
            if (arr[low] == key) return low; // Returns the index if the key is found
            return -1; // Returns -1 if the key is not found
        }

        // Estimate the position of the key using the interpolation formula
        int pos = low + ((double)(high - low) / (arr[high] - arr[low]) * (key - arr[low]));

        // Check if the key is found at the estimated position
        if (arr[pos] == key) {
            return pos; // Returns the index if the key is found
        }

        // If the key is larger, narrow the search range to the upper part
        if (arr[pos] < key) {
            low = pos + 1; // Updates the lower boundary
        } 
        // If the key is smaller, narrow the search range to the lower part
        else {
            high = pos - 1; // Updates the upper boundary
        }
    }
    return -1; // Returns -1 if the key is not found in the array
}

/**
 * Main function to demonstrate interpolation search.
 */
int main() {
    vector<int> arr = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23}; // Initializes a sorted array of integers
    int key = 18; // Specifies the key element to search for

    printInitialArray(arr); // Calls the function to print the initial array
    int index = interpolationSearch(arr, key); // Calls the interpolation search function and stores the result
    printResult(index, key); // Calls the function to print the result of the search

    return 0; // Returns 0 to indicate successful program execution
}