#include <iostream>
using namespace std;

#define M 5
#define N 6

void printSolution(char board[M][N])
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int countInColumns(char board[N][N], char ch, int j)
{
    int count = 0;
    for (int i = 0; i < M; i++)
    {
        if (board[i][j] == ch)
        {
            count++;
        }
    }

    return count;
}

int countInRow(char board[N][N], char ch, int i)
{
    int count = 0;
    for (int j = 0; j < N; j++)
    {
        if (board[i][j] == ch)
        {
            count++;
        }
    }

    return count;
}

bool isSafe(char board[N][N], int row, int col, char ch, int top[],
            int left[], int bottom[], int right[])
{
    if ((row - 1 >= 0 && board[row - 1][col] == ch) ||
        (col + 1 < N && board[row][col + 1] == ch) ||
        (row + 1 < M && board[row + 1][col] == ch) ||
        (col - 1 >= 0 && board[row][col - 1] == ch))
    {
        return false;
    }

    int rowCount = countInRow(board, ch, row);

    int colCount = countInColumns(board, ch, col);

    if (ch == '+')
    {
        if (top[col] != -1 && colCount >= top[col])
        {
            return false;
        }
        if (left[row] != -1 && rowCount >= left[row])
        {
            return false;
        }
    }
    if (ch == '-')
    {
        if (bottom[col] != -1 && colCount >= bottom[col])
        {
            return false;
        }
        if (right[row] != -1 && rowCount >= right[row])
        {
            return false;
        }
    }

    return true;
}

bool validateConfiguration(char board[N][N], int top[], int left[],
                           int bottom[], int right[])
{
    for (int i = 0; i < N; i++)
    {
        if (top[i] != -1 && countInColumns(board, '+', i) != top[i])
        {
            return false;
        }
    }
    for (int j = 0; j < M; j++)
    {
        if (left[j] != -1 && countInRow(board, '+', j) != left[j])
        {
            return false;
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (bottom[i] != -1 && countInColumns(board, '-', i) != bottom[i])
        {
            return false;
        }
    }
    for (int j = 0; j < M; j++)
    {
        if (right[j] != -1 && countInRow(board, '-', j) != right[j])
        {
            return false;
        }
    }

    return true;
}
bool solveMagnetPuzzle(char board[N][N], int row, int col, int top[],
                       int left[], int bottom[], int right[], char rules[M][N])
{
    if (row >= M - 1 && col >= N - 1)
    {
        if (validateConfiguration(board, top, left, bottom, right))
        {
            return true;
        }

        return false;
    }
    if (col >= N)
    {
        col = 0;
        row = row + 1;
    }
    if (rules[row][col] == 'R' || rules[row][col] == 'B')
    {
        if (solveMagnetPuzzle(board, row, col + 1, top,
                              left, bottom, right, rules))
        {
            return true;
        }
    }
    if (rules[row][col] == 'L' && rules[row][col + 1] == 'R')
    {
        if (isSafe(board, row, col, '+', top, left, bottom, right) &&
            isSafe(board, row, col + 1, '-', top, left, bottom, right))
        {
            board[row][col] = '+';
            board[row][col + 1] = '-';

            if (solveMagnetPuzzle(board, row, col + 2,
                                  top, left, bottom, right, rules))
            {
                return true;
            }
            board[row][col] = 'X';
            board[row][col + 1] = 'X';
        }
        if (isSafe(board, row, col, '-', top, left, bottom, right) &&
            isSafe(board, row, col + 1, '+', top, left, bottom, right))
        {
            board[row][col] = '-';
            board[row][col + 1] = '+';

            if (solveMagnetPuzzle(board, row, col + 2,
                                  top, left, bottom, right, rules))
            {
                return true;
            }
            board[row][col] = 'X';
            board[row][col + 1] = 'X';
        }
    }
    if (rules[row][col] == 'T' && rules[row + 1][col] == 'B')
    {
        if (isSafe(board, row, col, '+', top, left, bottom, right) &&
            isSafe(board, row + 1, col, '-', top, left, bottom, right))
        {
            board[row][col] = '+';
            board[row + 1][col] = '-';
            if (solveMagnetPuzzle(board, row, col + 1,
                                  top, left, bottom, right, rules))
            {
                return true;
            }
            board[row][col] = 'X';
            board[row + 1][col] = 'X';
        }
        if (isSafe(board, row, col, '-', top, left, bottom, right) &&
            isSafe(board, row + 1, col, '+', top, left, bottom, right))
        {
            board[row][col] = '-';
            board[row + 1][col] = '+';

            if (solveMagnetPuzzle(board, row, col + 1,
                                  top, left, bottom, right, rules))
            {
                return true;
            }
            board[row][col] = 'X';
            board[row + 1][col] = 'X';
        }
    }
    if (solveMagnetPuzzle(board, row, col + 1,
                          top, left, bottom, right, rules))
    {
        return true;
    }
    return false;
}

void solveMagnetPuzzle(int top[], int left[], int bottom[],
                       int right[], char rules[M][N])
{
    char board[M][N];
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            board[i][j] = 'X';
        }
    }
    if (!solveMagnetPuzzle(board, 0, 0, top, left, bottom, right, rules))
    {
        cout << "Solution does not exist";
        return;
    }
    printSolution(board);
}

int main()
{
    int top[N] = {1, -1, -1, 2, 1, -1};
    int bottom[N] = {2, -1, -1, 2, -1, 3};
    int left[M] = {2, 3, -1, -1, -1};
    int right[M] = {-1, -1, -1, 1, -1};
    char rules[M][N] =
        {
            {'L', 'R', 'L', 'R', 'T', 'T'},
            {'L', 'R', 'L', 'R', 'B', 'B'},
            {'T', 'T', 'T', 'T', 'L', 'R'},
            {'B', 'B', 'B', 'B', 'T', 'T'},
            {'L', 'R', 'L', 'R', 'B', 'B'}};

    solveMagnetPuzzle(top, left, bottom, right, rules);

    return 0;
}