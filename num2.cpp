#include <iostream>
#include <iomanip>
using namespace std;

double average(double num1, double num2) {
    return (num1 + num2) / 2;
}
int sumofsq(int num1, int num2) {
    return num1 * num1 + num2 * num2;
}
int squareofsum(int num1, int num2) {
    return (num1 + num2) * (num1 + num2);
}
int main() {
    double num1, num2;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
    cout << fixed << setprecision(2);
    cout << "The average of the two numbers is: " << average(num1, num2) << endl;
    cout << "The sum of the squares of the two numbers is: " << sumofsq(num1, num2) << endl;
    cout << "The square of the sum of the two numbers is: " << squareofsum(num1, num2) << endl;
    return 0;
}
