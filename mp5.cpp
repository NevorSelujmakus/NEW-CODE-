#include <iostream>
#include <vector>

using namespace std;

void mergeSort(vector<int>& numbers, int& comparisons, int& swaps) {
    if (numbers.size() <= 1) {
        return;
    }

    vector<int> left(numbers.begin(), numbers.begin() + numbers.size() / 2);
    vector<int> right(numbers.begin() + numbers.size() / 2, numbers.end());

    mergeSort(left, comparisons, swaps);
    mergeSort(right, comparisons, swaps);

    int i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size()) {
        comparisons++;
        if (left[i] < right[j]) {
            numbers[k++] = left[i++];
        } else {
            numbers[k++] = right[j++];
        }
        swaps++;
    }

    while (i < left.size()) {
        numbers[k++] = left[i++];
        swaps++;
    }

    while (j < right.size()) {
        numbers[k++] = right[j++];
        swaps++;
    }
}

int main() {
    int N;
    cout << "Enter the number of elements: ";
    std::cin >> N;

    vector<int> numbers(N);
    cout << "Enter the numbers: ";
    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
    }

    int comparisons, swaps;
    mergeSort(numbers, comparisons, swaps);

    cout << "Sorted numbers in ascending order: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Number of comparisons: " << comparisons << endl;
    cout << "Number of swaps: " << swaps << endl;

    return 0;
}