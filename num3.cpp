#include <iostream>
using namespace std;

const double LABOR_COST = 120.00;
const int SQFT_PER_GAL = 115;
const int HRS_PER_GAL = 8;

int calcGallons(int sqft) {
    return (sqft + SQFT_PER_GAL - 1) / SQFT_PER_GAL; // Ceiling division
}

int calcLaborHrs(int sqft) {
    return calcGallons(sqft) * HRS_PER_GAL;
}

double calcPaintCost(int sqft, double pricePerGal) {
    return calcGallons(sqft) * pricePerGal;
}

double calcLaborCost(int sqft) {
    return calcLaborHrs(sqft) * LABOR_COST;
}

double calcTotalCost(int sqft, double pricePerGal) {
    return calcPaintCost(sqft, pricePerGal) + calcLaborCost(sqft);
}

int main() {
    int numRooms;
    double pricePerGal;
    int totalSqft = 0;

    cout << "Enter the number of rooms to be painted: ";
    cin >> numRooms;

    cout << "Enter the price of the paint per gallon: ";
    cin >> pricePerGal;

    for (int i = 1; i <= numRooms; ++i) {
        int sqft;
        cout << "Enter the square feet of wall space in room " << i << ": ";
        cin >> sqft;
        totalSqft += sqft;
    }

    int gallonsReq = calcGallons(totalSqft);
    int laborHrsReq = calcLaborHrs(totalSqft);
    double paintCost = calcPaintCost(totalSqft, pricePerGal);
    double laborCost = calcLaborCost(totalSqft);
    double totalCost = calcTotalCost(totalSqft, pricePerGal);

    cout << "\nGallons of paint required: " << gallonsReq << endl;
    cout << "Hours of labor required: " << laborHrsReq << endl;
    cout << "Cost of the paint: $" << paintCost << endl;
    cout << "Labor charges: $" << laborCost << endl;
    cout << "Total cost of the paint job: $" << totalCost << endl;

    return 0;
}