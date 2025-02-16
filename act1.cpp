#include <iostream>
using namespace std;

void printDiamond(int size, int offset) {
    // Print the top part of the diamond
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < offset; ++j) {
            cout << " ";
        }
        for (int j = 0; j < size - i - 1; ++j) {
            cout << " ";
        }
        for (int j = 0; j < 2 * i + 1; ++j) {
            cout << "*";
        }
        cout << endl;
    }

    // Print the bottom part of the diamond
    for (int i = size - 2; i >= 0; --i) {
        for (int j = 0; j < offset; ++j) {
            cout << " ";
        }
        for (int j = 0; j < size - i - 1; ++j) {
            cout << " ";
        }
        for (int j = 0; j < 2 * i + 1; ++j) {
            cout << "*";
        }
        cout << endl;
    }
}


int main() {
    int sizes[] = {1, 5, 2, 6, 3}; // Sizes of the diamonds
    int offset = 0;

    for (int size : sizes) {
        printDiamond(size, offset);
        offset += 2 * size + 2; // Adjust offset for the next diamond
    }

    return 0;
}