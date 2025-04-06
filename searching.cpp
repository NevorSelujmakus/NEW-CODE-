#include<iostream>
#include<cmath>


using namespace std;

void linerSearch(int arr[], int n, int key){
    int comparisons = 0; // Counter for comparisons
    for(int i=0; i<n; i++){
        comparisons++;
        if(arr[i] == key){
            cout << "Element found at index " << i << endl;
            cout << "Number of comparisons: " << comparisons << endl;
            return;
        }
    }
    cout << "Element not found" << endl;
    cout << "Number of comparisons: " << comparisons << endl;
}

void binarySearch(int arr[], int n, int key){
    int comparisons = 0; // Counter for comparisons
    int low = 0, high = n-1;
    while(low <= high){
        comparisons++;
        int mid = (low + high) / 2;
        if(arr[mid] == key){
            cout << "Element found at index " << mid << endl;
            cout << "Number of comparisons: " << comparisons << endl;
            return;
        }
        else if(arr[mid] < key){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    cout << "Element not found" << endl;
    cout << "Number of comparisons: " << comparisons << endl;
}

void jumpSearch(int arr[], int n, int key) {
    int comparisons = 0; // Counter for comparisons
    int step = sqrt(n);  // Finding block size to be jumped
    int prev = 0;

    // Finding the block where the element is present (if it is present)
    while (arr[min(step, n) - 1] < key) {
        comparisons++;
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            cout << "Element not found" << endl;
            cout << "Number of comparisons: " << comparisons << endl;
            return;
        }
    }

    // Doing a linear search for the key in the block beginning with prev
    for (int i = prev; i < min(step, n); i++) {
        comparisons++;
        if (arr[i] == key) {
            cout << "Element found at index " << i << endl;
            cout << "Number of comparisons: " << comparisons << endl;
            return;
        }
    }

    cout << "Element not found" << endl;
    cout << "Number of comparisons: " << comparisons << endl;
}

void interpolationSearch(int arr[], int n, int key) {
    int comparisons = 0; // Counter for comparisons
    int low = 0, high = n - 1;

    while (low <= high && key >= arr[low] && key <= arr[high]) {
        comparisons++;

        // If the array has only one element
        if (low == high) {
            if (arr[low] == key) {
                cout << "Element found at index " << low << endl;
                cout << "Number of comparisons: " << comparisons << endl;
                return;
            }
            break;
        }

        // Estimate the position of the key
        int pos = low + ((double)(high - low) / (arr[high] - arr[low]) * (key - arr[low]));

        // Check if the key is found
        if (arr[pos] == key) {
            cout << "Element found at index " << pos << endl;
            cout << "Number of comparisons: " << comparisons << endl;
            return;
        }

        // If the key is larger, key is in the upper part
        if (arr[pos] < key) {
            low = pos + 1;
        }
        // If the key is smaller, key is in the lower part
        else {
            high = pos - 1;
        }
    }

    cout << "Element not found" << endl;
    cout << "Number of comparisons: " << comparisons << endl;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "Linear Search" << endl;
    linerSearch(arr, 10, 5);

    cout << "Binary Search" << endl;
    binarySearch(arr, 10, 5);
    
    cout << "Jump Search" << endl;
    jumpSearch(arr, 10, 5);
    
    cout << "Interpolation Search" << endl;
    interpolationSearch(arr, 10, 5);
    return 0;
}