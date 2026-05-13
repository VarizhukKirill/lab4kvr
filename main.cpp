#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;




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
            j--;
        }
        arr[j + 1] = key;
    }
}


void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) min_idx = j;
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



void printArray(const vector<int>& arr) {
    if (arr.size() > 20) {
        cout << "[Масив занадто великий для повного виводу]";
    } else {
        for (int x : arr) cout << x << " ";
    }
    cout << endl;
}

void generateRandom(vector<int>& arr, int size) {
    arr.clear();
    for (int i = 0; i < size; i++) {
        arr.push_back(rand() % 1000);
    }
}


void runTest(void (*sortFunc)(vector<int>&), vector<int> arr, string name) {
    cout << "\nТестування: " << name << endl;
    auto start = high_resolution_clock::now();

    sortFunc(arr);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Результат: ";
    printArray(arr);
    cout << "Час виконання: " << duration.count() << " мікросекунд" << endl;
}



int main() {
    srand(time(0));
    setlocale(LC_ALL, "Ukrainian");

    vector<int> currentArray;
    int choice = 0;
    int n = 10; // Розмір масиву за замовчуванням

    while (true) {

        cout << "1. Згенерувати новий випадковий масив" << endl;
        cout << "2. Показати поточний масив" << endl;
        cout << "3. Запустити Метод Бульбашки" << endl;
        cout << "4. Запустити Метод Вставки" << endl;
        cout << "5. Запустити Метод Вилучення" << endl;
        cout << "6. Запустити Метод Шелла" << endl;
        cout << "7. Запустити всі тести порівняння" << endl;
        cout << "0. Вийти з програми" << endl;
        cout << "Ваш вибір: ";
        cin >> choice;

        if (choice == 0) break;

        switch (choice) {
            case 1:
                cout << "Введіть розмір масиву: ";
                cin >> n;
                generateRandom(currentArray, n);
                cout << "Масив згенеровано." << endl;
                break;
            case 2:
                cout << "Поточний масив: ";
                printArray(currentArray);
                break;
            case 3:
                runTest(bubbleSort, currentArray, "Bubble Sort");
                break;
            case 4:
                runTest(insertionSort, currentArray, "Insertion Sort");
                break;
            case 5:
                runTest(selectionSort, currentArray, "Selection Sort");
                break;
            case 6:
                runTest(shellSort, currentArray, "Shell Sort");
                break;
            case 7:
                runTest(bubbleSort, currentArray, "Bubble Sort");
                runTest(insertionSort, currentArray, "Insertion Sort");
                runTest(selectionSort, currentArray, "Selection Sort");
                runTest(shellSort, currentArray, "Shell Sort");
                break;
            default:
                cout << "Невірний вибір, спробуйте ще раз." << endl;
        }
    }

    cout << "Програма завершена. Дякуємо за використання!" << endl;
    return 0;
}

// КІНЕЦЬ ФАЙЛУ
// Рядок 155 (приблизно)