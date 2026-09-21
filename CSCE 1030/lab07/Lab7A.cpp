#include <iostream>
using namespace std;

int main() {
    const int ROW_SIZE = 2;
    const int COLUMN_SIZE = 5;
    int matrix[ROW_SIZE][COLUMN_SIZE];
    for (int i = 0; i < ROW_SIZE; i++)
    {
        for (int j = 0; j < COLUMN_SIZE; j++)
        {
            cout << "Enter data for row #" << i + 1 << " and column #" << j + 1 << ": "; cin >> matrix[i][j];
        }
    }

    int min_row[ROW_SIZE]; // Compute the minimum value of each row
    int min_col[COLUMN_SIZE]; //Compute the minimum value of each column
    for (int i = 0; i < ROW_SIZE; i++)
    {
        min_row[i] = matrix[i][0];
        for (int j = 0; j < COLUMN_SIZE; j++)
        {
            if (matrix[i][j] < min_row[i])
            {
                min_row[i] = matrix[i][j];
            }
        }
    }
    for (int i = 0; i < COLUMN_SIZE; i++)
    {
        min_col[i] = matrix[0][i];
        for (int j = 0; j < ROW_SIZE; j++)
        {
            if (matrix[j][i] < min_col[i])
            {
                min_col[i] = matrix[j][i];
            }
        }
    }

    cout << "You entered: " << endl;
    for (int i = 0; i < ROW_SIZE; i++)
    {
        for (int j = 0; j < COLUMN_SIZE; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < ROW_SIZE; i++)
    {
        cout << "Minimum of row " << i << ": " << min_row[i] << endl;
    }
    cout << "The minimum value of each column is: " << endl;
    for (int i = 0; i < COLUMN_SIZE; i++)
    {
        cout << "Minimum of column " << i << ": " << min_col[i] << endl;
    }
    cout << endl;

    return 0;
}
