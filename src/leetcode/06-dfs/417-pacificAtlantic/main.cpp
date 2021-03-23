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
    vector<vector<bool>> ao;
    vector<vector<bool>> po;

    vector<vector<int>> res;

    bool inArea(int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    // flag true -> ao, false -> po
    void dfs(const vector<vector<int>> &matrix, int x, int y, bool flag) {
        visited[x][y] = true;
        if (flag)
            ao[x][y] = true;
        else
            po[x][y] = true;

        for(auto move : moves) {
            int nX = x + move[0];
            int nY = y + move[1];
            if (inArea(nX, nY) && !visited[nX][nY] && matrix[x][y] <= matrix[nX][nY])
                dfs(matrix, nX, nY, flag);
        }

        visited[x][y] = false;
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix) {
        m = matrix.size();
        if (m == 0) return res;
        n = matrix[0].size();
        if (n == 0) return res;

        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        ao = vector<vector<bool>>(m, vector<bool>(n, false));
        po = vector<vector<bool>>(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            if (!visited[i][0]) dfs(matrix, i, 0, false);
            if (!visited[i][n - 1]) dfs(matrix, i, n - 1, true);
        }

        for (int j = 0; j < n; ++j) {
            if (!visited[0][j]) dfs(matrix, 0, j, false);
            if (!visited[m - 1][j]) dfs(matrix, m - 1, j, true);
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (po[i][j] && ao[i][j]) {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};

int main(int argc, char *argv[]) {
    vector<vector<int>> matrix = {{1, 2, 2, 3, 5},
                                  {3, 2, 3, 4, 4},
                                  {2, 4, 5, 3, 1},
                                  {6, 7, 1, 4, 5},
                                  {5, 1, 1, 2, 4}};
    vector<vector<int>> res = Solution().pacificAtlantic(matrix);
    for (auto &vec : res) {
        for (auto k : vec) {
            cout << k << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}