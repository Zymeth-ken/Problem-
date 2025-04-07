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

void printResult(const string& searchType, int index, int key, int comparisons, int searchNumber) {
    cout << endl;
    cout << searchType << " Search (" << searchNumber << "):" << endl;
    cout << endl;
    if (index != -1) {
        cout << "Element " << key << " found at index " << index << endl;
    } else {
        cout << "Element " << key << " not found in the array" << endl;
    }
    cout << "Number of comparisons: " << comparisons << endl;
    cout << endl;
}

int linearSearch(const vector<int>& arr, int key, int& comparisons) {
    for (int i = 0; i < arr.size(); i++) {
        comparisons++;
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int binarySearch(const vector<int>& arr, int key, int& comparisons) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        comparisons++;
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int jumpSearch(const vector<int>& arr, int key, int& comparisons) {
    int n = arr.size();
    int step = sqrt(n);
    int prev = 0;

    while (arr[min(step, n) - 1] < key) {
        comparisons++;
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            return -1;
        }
    }

    for (int i = prev; i < min(step, n); i++) {
        comparisons++;
        if (arr[i] == key) {
            return i;
        }
    }

    return -1;
}

int interpolationSearch(const vector<int>& arr, int key, int& comparisons) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high && key >= arr[low] && key <= arr[high]) {
        comparisons++;
        if (low == high) {
            if (arr[low] == key) return low;
            return -1;
        }

        int pos = low + ((double)(high - low) / (arr[high] - arr[low]) * (key - arr[low]));

        if (arr[pos] == key) {
            return pos;
        }

        if (arr[pos] < key) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23};
    int key = 18;

    printInitialArray(arr);

    int comparisons = 0;
    int index = linearSearch(arr, key, comparisons);
    printResult("Linear", index, key, comparisons, 1);

    comparisons = 0;
    index = binarySearch(arr, key, comparisons);
    printResult("Binary", index, key, comparisons, 2);

    comparisons = 0;
    index = jumpSearch(arr, key, comparisons);
    printResult("Jump", index, key, comparisons, 3);

    comparisons = 0;
    index = interpolationSearch(arr, key, comparisons);
    printResult("Interpolation", index, key, comparisons, 4);

    return 0;
}