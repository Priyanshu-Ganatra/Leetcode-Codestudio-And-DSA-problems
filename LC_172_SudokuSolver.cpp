#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSafe(int row, int col, char value, vector<vector<char>> &board)
    {
        // the character mustn't be in already present in the
        // same row, col, and the same 3x3 matrix(sub-box)
        int n = board.size();
        for (int i = 0; i < n; i++)
        {
            // row check
            if (board[row][i] == value)
                return false;

            // col check
            if (board[i][col] == value)
                return false;

            // 3*3 box check
            int startRow = 3 * (row / 3);
            int startCol = 3 * (col / 3);
            if (board[startRow + (i / 3)][startCol + (i % 3)] == value)
                return false;
        }
        // place is safe
        return true;
    }

    bool solve(vector<vector<char>> &board)
    {
        int n = board.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // check for empty cell
                if (board[i][j] == '.')
                {
                    // try to insert 1->9
                    for (char ch = '1'; ch <= '9'; ch++)
                    {
                        if (isSafe(i, j, ch, board))
                        {
                            // place
                            board[i][j] = ch;
                            // recursion
                            bool recursionAns = solve(board);
                            if (recursionAns == true)
                            {
                                return true;
                            }
                            else
                            {
                                // if recursion returns false, it means
                                // we had inserted incorrect character
                                // so we backtrack
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
};

int main()
{
    Solution obj;
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    obj.solveSudoku(board);
    for (auto vec : board)
    {
        for (auto ch : vec)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
    return 0;
}