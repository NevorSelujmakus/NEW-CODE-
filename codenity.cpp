#include <iostream>
using namespace std;

int main() {
    int width = 15;   // Width of each tower
    int height = 6;   // Height of each tower
    int spacing = 5;  // Space between towers
    int baseHeight = 4; // Castle base height

    // Castle Battlements (Crenellations)
    for (int i = 0; i < 3; i++) {
        cout << "|";
        for (int j = 0; j < width - 2; j++) {
            if (j % 4 == 0) cout << "^"; // Battlements
            else cout << " ";
        }
        cout << "|";

        for (int j = 0; j < spacing; j++) cout << " "; // Space between towers

        cout << "|";
        for (int j = 0; j < width - 2; j++) {
            if (j % 4 == 0) cout << "^"; // Battlements
            else cout << " ";
        }
        cout << "|" << endl;
    }

    // Towers' Walls
    for (int i = 0; i < height; i++) {
        cout << "|";
        for (int j = 0; j < width - 2; j++) {
            if ((i == 2 || i == 4) && (j == 3 || j == 9)) cout << "O"; // Windows
            else cout << " ";
        }
        cout << "|";

        for (int j = 0; j < spacing; j++) cout << " "; // Space between towers

        cout << "|";
        for (int j = 0; j < width - 2; j++) {
            if ((i == 2 || i == 4) && (j == 3 || j == 9)) cout << "O"; // Windows
            else cout << " ";
        }
        cout << "|" << endl;
    }

    // Castle Walls and Entrance
    for (int i = 0; i < baseHeight; i++) {
        cout << "|";
        for (int j = 0; j < width - 2; j++) {
            if (i == baseHeight - 2 && (j >= width / 2 - 2 && j <= width / 2 + 2)) cout << "O"; // Arched Entrance
            else cout << "#";
        }
        cout << "|";

        for (int j = 0; j < spacing; j++) cout << "#"; // Wall between towers

        cout << "|";
        for (int j = 0; j < width - 2; j++) {
            if (i == baseHeight - 2 && (j >= width / 2 - 2 && j <= width / 2 + 2)) cout << "O";
            else cout << "#";
        }
        cout << "|" << endl;
    }
    cout << "+";
    for (int i = 0; i < width - 2; i++) cout << "-";
    cout << "+";

    for (int i = 0; i < spacing; i++) cout << "-";

    cout << "+";
    for (int i = 0; i < width - 2; i++) cout << "-";
    cout << "+" << endl;

    return 0;
}