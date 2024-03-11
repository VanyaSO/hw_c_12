#include <iostream>
using namespace std;

// Написати функцію, що додає рядок двовимірному масиву на початок.


void init2DArray(int**& arr, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        arr[i] = new int[cols];
    }

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            arr[i][j] = rand() % 10;
        }
    }
}

void print2DArray(int** arr, int rows, int cols)
{
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void delete2DArray(int** arr, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}

void addRowToStart2DArr(int**& arr, int& rows, int cols)
{
    int** newArr = new int* [rows + 1];

    newArr[0] = new int [cols];

    for (int i = 0, j = 1; i <= rows; ++i) {
        newArr[j++] = arr[i];
    }

    for (int i = 0; i < cols; ++i) {
        newArr[0][i] = rand() % 10;
    }

    delete[] arr;
    rows++;
    arr = newArr;
}

int main() {

    srand(time(0));
    int cols = 3, rows = 3;
    int** arr = new int*[rows];

    init2DArray(arr, rows, cols);
    addRowToStart2DArr(arr, rows, cols);
    print2DArray(arr, cols, rows);
    delete2DArray(arr, rows);

    return 0;
}