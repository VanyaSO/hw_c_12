#include <iostream>
using namespace std;

// Написати функцію, що додає рядок двовимірному масиву в зазначену позицію.

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

void addElByIndexTo2DArr(int**& arr, int& rows, int cols, int index)
{
    if (index < 0 || index > rows-1 || index > cols-1)
    {
        cout << "Error: index not found";
        return;
    }

    int** newArr = new int* [rows + 1];

    for (int i = 0, j = 0; i < rows; ++i, ++j) {
        if(i == index)
        {
            newArr[j] = new int[cols];
            for (int k = 0; k < cols; ++k) {
                newArr[j][k] = rand() % 10;
            }
            j++;
        }
        newArr[j] = arr[i];
    }

    delete[] arr;
    rows++;
    arr = newArr;
}

int main() {

    srand(time(0));
    int cols = 3, rows = 3;
    int** arr = new int*[rows];
    int index;
    cout << "Enter index: " << endl;
    cin >> index;
    cout << endl;


    init2DArray(arr, rows, cols);
    addElByIndexTo2DArr(arr, rows, cols, index);
    print2DArray(arr, rows, cols);
    delete2DArray(arr, rows);

    return 0;
}