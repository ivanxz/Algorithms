//
// Created by 谢卓 on 2021/3/23.
//

#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
//        int m = obstacleGrid.size();
//        int n = obstacleGrid[0].size();
//
//        vector<vector<int>> dp(m, vector<int>(n));
//        dp[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
//        for (int i = 1; i < m; ++i) {
//            dp[i][0] = obstacleGrid[i][0] == 1 ? 0 : dp[i - 1][0];
//        }
//
//        for (int j = 1; j < n; ++j) {
//            dp[0][j] = obstacleGrid[0][j] == 1 ? 0 : dp[0][j - 1];
//        }
//
//        for (int i = 1; i < m; ++i) {
//            for (int j = 1; j < n; ++j) {
//                dp[i][j] = obstacleGrid[i][j] == 1 ? 0 : dp[i - 1][j] + dp[i][j - 1];
//            }
//        }
//
//        return dp[m - 1][n - 1];
//    }
//};

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<int> dp(n);
        dp[0] = obstacleGrid[0][0] == 1 ? 0 : 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                    continue;
                }

                if (j - 1 >= 0 && obstacleGrid[i][j] == 0)
                    dp[j] += dp[j - 1];
            }
        }

        return dp.back();
    }
};

int main(int argc, char *argv[]) {
    vector<vector<int>> obstacleGrid = {{1, 0, 0},
                                        {0, 1, 0},
                                        {0, 0, 0}};
    cout << Solution().uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}