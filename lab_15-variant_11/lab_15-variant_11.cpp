#include <iostream>;
#include "windows.h";
#include <string>;
#include "Header.h";
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string inputString;
    int defaultSize = 10;
    cout << "Введіть кількіть елементів масиву (або натисніть Enter, щоб залишити значення " << defaultSize << " за замовчуванням): ";
    getline(cin, inputString);

    int size = strToNonNegativeInt(inputString);
    if (size < 0) size = defaultSize;
    cout << "Розмір масиву встановлено на " << size << " елементів. Елементи масиву:" << endl;

    int *arrayOfInt = new int[size];
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arrayOfInt[i] = rand() % 41 - 20;
        cout << arrayOfInt[i] << " ";
    }
    cout << endl << endl;

    cout << "Відсортований масив (від'ємні елементи спочатку, нулі наприкінці):" << endl;
    arrayWithNegativesFirstZerosLast(arrayOfInt, size);
    for (int i = 0; i < size; i++) cout << arrayOfInt[i] << " ";

    cout << endl << endl << "Відсортований масив:" << endl;
    quickSort(arrayOfInt, size - 1);
    for (int i = 0; i < size; i++) cout << arrayOfInt[i] << " ";

    string sortedCaption = isSorted(arrayOfInt, size) ? "Так, масив відсортовано" : "Ні, масив не відсортовано";
    cout << endl << "Проведемо перевірку, чи насправді масив відсортовано: " << sortedCaption << endl;
}

int strToNonNegativeInt(string str) {
    int temp;
    try {
        temp = stoi(str);
    }
    catch (...) {
        temp = -1;
    }
    return temp;
}

void switchElements(int* a, int from, int dest) {
    int temp = a[from];
    a[from] = a[dest];
    a[dest] = temp;
}

void arrayWithNegativesFirstZerosLast(int* a, int size) {
    int index = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] < 0) {
            if (i > index) switchElements(a, i, index);
            index++;
        }
    }
    int startIndex = index; index = size - 1;
    for (int i = size - 1; i >= startIndex; i--) {
        if (a[i] == 0) {
            if (i < index) switchElements(a, i, index);
            index--;
        }
    }
}

void quickSort(int* a, int high, int low) {
    int i = low, j = high, b = a[rand() % (high - low + 1) + low];
    while (i <= j) {
        while (a[i] < b) i++;
        while (a[j] > b) j--;
        if (i >= j) break;
        switchElements(a, i++, j--);
    }
    if (j > low) quickSort(a, j, low);
    if (high > j + 1) quickSort(a, high, j + 1);
}

bool isSorted(int* a, int count) {
    for (int i = 1; i < count; i++) if (a[i] < a[i - 1]) return false;
    return true;
}