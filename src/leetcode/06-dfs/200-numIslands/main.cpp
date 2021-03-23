//
// Created by 谢卓 on 2021/3/19.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    const int moves[4][2] = {{0,-1}, {1, 0}, {0, 1}, {-1, 0}};
    int m{}, n{};
    vector<vector<bool>> visited;

    bool inArea(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    void dfs(const vector<vector<char>> &grid, int x, int y) {
        visited[x][y] = true;
        for(auto move : moves) {
            int nX = x + move[0];
            int nY = y + move[1];
            if (inArea(nX, nY) && !visited[nX][nY] && grid[nX][nY] == '1')
                dfs(grid, nX, nY);
        }
    }

public:
    int numIslands(vector<vector<char>> &grid) {
        int res = 0;
        m = grid.size();
        n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    res++;
                    dfs(grid, i, j);
                }
            }
        }

        return res;
    }
};

int main(int argc, char *argv[]) {
    vector<vector<char>> grid = {{'1', '1', '1', '1', '0'},
                                 {'1', '1', '0', '1', '0'},
                                 {'1', '1', '0', '0', '0'},
                                 {'0', '0', '0', '0', '0'}};
    cout << Solution().numIslands(grid) << endl;
    return 0;
}