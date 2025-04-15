#include <stdio.h>
#include <math.h>

int possibleCount = 0;

int checkSafe(int arr[], int row, int col)
{
    int isSafe = 1;
    for (int i = 1; i < row; i++)
    {
        if ((arr[i] == col) || (fabs(i - row) == fabs(arr[i] - col)))
        {
            isSafe = 0;
            break;
        }
    }
    return isSafe;
}

void nQueens(int arr[], int row)
{
    if (row == 9)
    {
        possibleCount++;
        return;  
    }

    for (int col = 1; col <= 8; col++)
    {
        if (checkSafe(arr, row, col))
        {
            arr[row] = col;       
            nQueens(arr, row + 1);
            arr[row] = 0;         
        }
    }
}

int main()
{
    int arr[9] = {0};
    nQueens(arr, 1);
    printf("The Maximum Possible Combination for Placing 8 distinct Queens is: %d\n", possibleCount);
    return 0;
}
