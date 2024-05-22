#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<int, bool> rowCheck;
    unordered_map<int, bool> topDiagCheck;
    unordered_map<int, bool> bottomDiagCheck;

    void storeSoln(vector<vector<char>> &board, vector<vector<string>> &ans)
    {
        vector<string> tempSol;
        for (auto vec : board)
        {
            string temp = "";
            for (auto ch : vec)
            {
                temp += ch;
            }
            tempSol.push_back(temp);
        }
        ans.push_back(tempSol);
    }

    bool isSafe(int row, int col, vector<vector<char>> &board)
    {
        // check if there is a queen in the same row
        if (rowCheck[row])
            return false;
        // check if there is a queen in the top diagonal
        if (topDiagCheck[row - col])
            return false;
        // check if there is a queen in the bottom diagonal
        if (bottomDiagCheck[row + col])
            return false;
        return true;
    }

    void solve(vector<vector<char>> board, vector<vector<string>> &ans, int n, int col)
    {
        // bc
        if (col >= n)
        {
            // all columns are filled
            storeSoln(board, ans);
            return;
        }
        // main logic
        // try to place a queen on this column's each row
        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, board))
            {
                // place a queeen
                board[row][col] = 'Q';
                // mark all the 3 directions which indicate that a queen is placed here
                rowCheck[row] = true;
                topDiagCheck[row - col] = true;
                bottomDiagCheck[row + col] = true;

                // recursive call
                solve(board, ans, n, col + 1);
                // backtrack
                board[row][col] = '.';
                rowCheck[row] = false;
                topDiagCheck[row - col] = false;
                bottomDiagCheck[row + col] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<vector<char>> board(n, vector<char>(n, '.'));
        int col = 0;
        solve(board, ans, n, col);
        return ans;
    }
};