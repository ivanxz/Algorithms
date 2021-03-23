//
// Created by 谢卓 on 2021/3/19.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    const int moves[4][2] = {{0,  -1},
                             {1,  0},
                             {0,  1},
                             {-1, 0}};
    int m{}, n{};

    bool isEdge(int x, int y) {
        return x == 0 || x == m - 1 || y == 0 || y == n - 1;
    }

    void dfs(vector<vector<char>> &board, int x, int y) {
        if (x < 0 || y < 0 || x >= m || y >= n || board[x][y] == '#' || board[x][y] == 'X')
            return;

        board[x][y] = '#';
        for (auto move : moves) {
            int nX = x + move[0];
            int nY = y + move[1];
            dfs(board, nX, nY);
        }
    }

public:
    void solve(vector<vector<char>> &board) {
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isEdge(i, j) && board[i][j] == 'O') {
                    dfs(board, i, j);
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};

int main(int argc, char *argv[]) {
    vector<vector<char>> board = {{'X', 'X', 'X', 'X'},
                                  {'X', 'O', 'O', 'X'},
                                  {'X', 'X', 'O', 'X'},
                                  {'X', 'O', 'X', 'X'}};
    vector<vector<char>> board1 = {{'O', 'O', 'O'},
                                   {'O', 'O', 'O'},
                                   {'O', 'O', 'O'}};
    Solution().solve(board);
    for (auto &vec : board) {
        for (auto c : vec) {
            cout << c << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}