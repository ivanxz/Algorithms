//
// Created by 谢卓 on 2021/3/23.
//

#include <iostream>
#include <vector>

using namespace std;

//// 动态规划
//class Solution {
//public:
//    int minPathSum(vector<vector<int>> &grid) {
//        int m = grid.size();
//        int n = grid[0].size();
//        auto dp = vector<vector<int>>(m, vector<int>(n));
//        dp[0][0] = grid[0][0];
//        for (int i = 1; i < m; ++i) {
//            dp[i][0] = dp[i - 1][0] + grid[i][0];
//        }
//
//        for (int j = 1; j < n; ++j) {
//            dp[0][j] = dp[0][j - 1] + grid[0][j];
//        }
//
//        for (int i = 1; i < m; ++i) {
//            for (int j = 1; j < n; ++j) {
//                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
//            }
//        }
//
//        return dp[m - 1][n - 1];
//    }
//};

// 动态规划 + 空间优化
class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;
                else if (i == 0) grid[i][j] = grid[i][j - 1] + grid[i][j];
                else if (j == 0) grid[i][j] = grid[i - 1][j] + grid[i][j];
                else grid[i][j] = min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
            }
        }

        return grid[m - 1][n - 1];
    }
};

int main(int argc, char *argv[]) {
    vector<vector<int>> grid{{1, 3, 1},
                             {1, 5, 1},
                             {4, 2, 1}};
    cout << Solution().minPathSum(grid) << endl;
    return 0;
}