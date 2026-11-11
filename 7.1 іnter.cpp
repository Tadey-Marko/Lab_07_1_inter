
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

// Створення двовимірного масиву
int** makeMatrix(int rows, int cols) {
    int** a = new int* [rows];

    for (int i = 0; i < rows; i++) {
        a[i] = new int[cols];
    }

    return a;
}

// Заповнення матриці випадковими числами
void fillMatrix(int** a, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            a[i][j] = -42 + rand() % 94;
        }
    }
}

// Виведення матриці
void printMatrix(int** a, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << a[i][j];
        }
        cout << endl;
    }
}

// Перевірка елементів за умовою
bool selected(int x) {
    return !(x > 0 && x % 5 == 0);
}

// Підрахунок кількості та суми елементів
void countAndSum(int** a, int rows, int cols,
    int& count, int& sum) {
    count = 0;
    sum = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (selected(a[i][j])) {
                count++;
                sum += a[i][j];
            }
        }
    }
}

// Заміна вибраних елементів нулями
void replaceSelected(int** a, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (selected(a[i][j])) {
                a[i][j] = 0;
            }
        }
    }
}

// Порівняння рядків для сортування
bool rowGreater(int* x, int* y) {
    if (x[0] != y[0]) {
        return x[0] > y[0];
    }

    if (x[1] != y[1]) {
        return x[1] < y[1];
    }

    return x[2] > y[2];
}

// Сортування рядків матриці
void sortRows(int** a, int rows) {
    for (int i = 0; i < rows - 1; i++) {
        for (int j = 0; j < rows - i - 1; j++) {
            if (rowGreater(a[j], a[j + 1])) {
                int* temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

// Звільнення пам'яті
void freeMatrix(int** a, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] a[i];
    }

    delete[] a;
}

int main() {
    srand(3);

    const int rows = 7;
    const int cols = 6;

    int** t = makeMatrix(rows, cols);

    fillMatrix(t, rows, cols);

    cout << "Original matrix:" << endl;
    printMatrix(t, rows, cols);

    // Завдання 7.1
    int count = 0;
    int sum = 0;

    countAndSum(t, rows, cols, count, sum);

    cout << "\nCount = " << count << endl;
    cout << "Sum = " << sum << endl;

    replaceSelected(t, rows, cols);

    cout << "\nMatrix after replacement:" << endl;
    printMatrix(t, rows, cols);

    freeMatrix(t, rows);

    // Завдання 7.2
    srand(3);

    t = makeMatrix(rows, cols);
    fillMatrix(t, rows, cols);

    cout << "\nMatrix before sorting:" << endl;
    printMatrix(t, rows, cols);

    sortRows(t, rows);

    cout << "\nMatrix after sorting:" << endl;
    printMatrix(t, rows, cols);

    freeMatrix(t, rows);

    return 0;
}
