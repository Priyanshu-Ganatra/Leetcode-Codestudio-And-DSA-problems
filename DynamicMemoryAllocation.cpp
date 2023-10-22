#include <iostream>

using namespace std;

void print(int **v, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    // // 1. allocate single int
    // int *intPtr = new int(5);

    // // allocate single int using malloc
    // int *mptr = (int *)malloc(4);
    // *mptr = 5;

    // cout << *intPtr << " " << *mptr << endl;
    // delete intPtr;
    // free(mptr);

    // // 1D array allocation
    // int *arrnew = new int[5];

    // // 1D array allocation using malloc
    // int *arrmalloc = (int *)malloc(5 * sizeof(int));

    // for (int i = 0; i < 5; i++)
    // {
    //     int d;
    //     cin >> d;
    //     arrnew[i] = arrmalloc[i] = d;
    // }

    // for (int i = 0; i < 5; i++)
    // {
    //     cout << arrnew[i] << " " << arrmalloc[i] << endl;
    // }
    // delete[] arrnew;
    // free(arrmalloc);

    // 2D array allocation
    int rows = 5, cols = 5;
    int **ptr2d = new int *[rows];

    // 2D array allocation using malloc
    for (int i = 0; i < rows; ++i)
        ptr2d[i] = new int[cols];

    int **ptr2dmalloc = (int **)malloc(sizeof(int *) * rows);
    for (int i = 0; i < rows; i++)
        ptr2dmalloc[i] = (int *)malloc(sizeof(int) * cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            ptr2d[i][j] = 7;
            ptr2dmalloc[i][j] = 8;
        }
    }

    print(ptr2d, rows, cols);
    print(ptr2dmalloc, rows, cols);

    for (int i = 0; i < rows; ++i)
        delete[] ptr2d[i];
    delete[] ptr2d;

    for (int i = 0; i < rows; ++i)
        free(ptr2dmalloc[i]);
    free(ptr2dmalloc);
    return 0;
}