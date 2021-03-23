//
// Created by 谢卓 on 2021/3/19.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    const int moves[4][2] = {{-1, 0},{0, 1}, {1, 0}, {0, -1}};
    int m{}, n{};
    vector<vector<bool>> visited;

    bool inArea(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    bool dfs(const vector<vector<char>> &board, const string& word, int x, int y, int index) {
        if (index == word.length() - 1)
            return word[index] == board[x][y];

        if (word[index] == board[x][y]) {
            visited[x][y] = true;
            for (auto move : moves) {
                int nX = x + move[0];
                int nY = y + move[1];
                if (inArea(nX, nY) && !visited[nX][nY] && dfs(board, word, nX, nY, index + 1))
                    return true;
            }

            visited[x][y] = false;
        }

        return false;
    }

public:
    bool exist(vector<vector<char>> &board, string word) {
        m = board.size();
        n = board[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if(dfs(board, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};

int main(int argc, char *argv[]) {
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                                  {'S', 'F', 'C', 'S'},
                                  {'A', 'D', 'E', 'E'}};
    cout << Solution().exist(board, "ABCB") << endl;
    return 0;
}