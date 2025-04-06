#include <iostream>
#include <iomanip>
using namespace std;

double retail(double cost, int markup) {
    return cost + (cost * markup / 100);
}

int main() {
    double cost;
    int markup;
    cout << "Enter the cost of the item: ";
    cin >> cost;
    cout << "Enter the markup percentage: ";
    cin >> markup;
    cout << fixed << setprecision(2);
    cout << "The retail price is: $" << retail(cost, markup) << endl;
    return 0;
}