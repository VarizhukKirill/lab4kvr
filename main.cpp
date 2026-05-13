#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void printArray(const vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}


void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}


void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}


void shellSort(vector<int>& arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

int main() {
    // Початковий масив
    const vector<int> original = {64, 34, 25, 12, 22, 11, 90};
    vector<int> arr;

    cout << "=== Програма сортування масивів ===" << endl;
    cout << "Початковий масив: ";
    printArray(original);
    cout << "-----------------------------------" << endl;


    arr = original;
    bubbleSort(arr);
    cout << "1. Метод бульбашки:  ";
    printArray(arr);


    arr = original;
    insertionSort(arr);
    cout << "2. Метод вставки:    ";
    printArray(arr);


    arr = original;
    selectionSort(arr);
    cout << "3. Метод вилучення:  ";
    printArray(arr);


    arr = original;
    shellSort(arr);
    cout << "4. Метод Шелла:      ";
    printArray(arr);

    cout << "-----------------------------------" << endl;
    return 0;
}