#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void printInitialArray(const vector<int>& arr) {
    cout << "Initial array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

void printResult(int index, int comparisons) {
    if (index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }
    cout << "Number of comparisons: " << comparisons << endl;
}

int jumpSearch(const vector<int>& arr, int x, int& comparisons) {
    int n = arr.size();
    int step = sqrt(n);
    int prev = 0;

    while (arr[min(step, n) - 1] < x) {
        comparisons++;
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            return -1; 
        }
    }

    for (int i = prev; i < min(step, n); i++) {
        comparisons++;
        if (arr[i] == x) {
            return i; 
        }
    }

    return -1; 
}

int main() {
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int x = 4;
    int comparisons = 0;

    printInitialArray(arr);
    int result = jumpSearch(arr, x, comparisons);
    printResult(result, comparisons);

    return 0;
}