#include <iostream>
using namespace std;

// Написати функцію, що додає рядок двовимірному масиву в кінець.

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

void addRowTo2DArr(int**& arr, int& rows, int cols)
{
    int** newArr = new int* [rows + 1];

    for (int i = 0; i < rows; ++i) {
        newArr[i] = arr[i];
    }

    newArr[rows] = new int[cols];
    for (int i = 0; i < cols; ++i) {
        newArr[rows][i] = rand() % 10;
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
    addRowTo2DArr(arr, rows, cols);
    print2DArray(arr, rows, cols);
    delete2DArray(arr, rows);
    return 0;
}