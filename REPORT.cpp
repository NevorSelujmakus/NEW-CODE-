#include <iostream>
using namespace std;

// FUNCTION OVERLOADING
int sum(int a);
int sum(int a, int b);
int sum(int a, int b, int c);

int main() {
    cout << sum(10) << endl;
    cout << sum(10, 5) << endl;
    cout << sum(10, 5, 5) << endl;
    system("pause");
    return 0;
}

int sum(int a) {
    return a + 2;
}

int sum(int a, int b) {
    return a + b;
}

int sum(int a, int b, int c) {
    return a + b + c;
}