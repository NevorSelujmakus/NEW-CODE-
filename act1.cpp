#include <iostream>

void printDiamond(int size) {
    // Print the top part of the diamond
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            std::cout << " ";
        }
        for (int j = 0; j < 2 * i + 1; ++j) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    // Print the bottom part of the diamond
    for (int i = size - 2; i >= 0; --i) {
        for (int j = 0; j < size - i - 1; ++j) {
            std::cout << " ";
        }
        for (int j = 0; j < 2 * i + 1; ++j) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

int main() {
    int sizes[] = {9, 7, 5, 3, 1}; // Sizes of the diamonds

    for (int size : sizes) {
        printDiamond(size);
        std::cout << std::endl; // Add a blank line between diamonds
    }

    return 0;
}