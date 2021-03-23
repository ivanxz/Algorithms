//
// Created by 谢卓 on 2021/3/23.
//

#include <iostream>
#include <vector>

using namespace std;

//// 递归
//class Solution {
//private:
//    int dfs(const vector<vector<int>> &triangle, int i, int j) {
//        if (i == triangle.size()) {
//            return 0;
//        }
//
//        return min(dfs(triangle, i + 1, j), dfs(triangle, i + 1, j + 1)) + triangle[i][j];
//    }
//public:
//    int minimumTotal(vector<vector<int>> &triangle) {
//        return dfs(triangle, 0, 0);
//    }
//};

//// 递归+记忆化搜索
//class Solution {
//private:
//    vector<vector<int>> memo;
//    int dfs(const vector<vector<int>> &triangle, int i, int j) {
//        if (i == triangle.size()) {
//            return 0;
//        }
//
//        if (memo[i][j] == -1)
//            memo[i][j] = min(dfs(triangle, i + 1, j), dfs(triangle, i + 1, j + 1)) + triangle[i][j];
//
//        return memo[i][j];
//    }
//public:
//    int minimumTotal(vector<vector<int>> &triangle) {
//        int n = triangle.size();
//        memo = vector<vector<int>>(n, vector<int>(n, -1));
//        return dfs(triangle, 0, 0);
//    }
//};

//// 动态规划
//class Solution {
//public:
//    int minimumTotal(vector<vector<int>> &triangle) {
//        int n = triangle.size();
//        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
//        for (int i = n - 1; i >= 0; --i) {
//            for (int j = 0; j <= i; ++j) {
//                dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
//            }
//        }
//
//        return dp[0][0];
//    }
//};

//// 动态规划 + 空间优化 + 自底向上
//class Solution {
//public:
//    int minimumTotal(vector<vector<int>> &triangle) {
//        int n = triangle.size();
//        vector<int> dp(n + 1);
//        for (int i = n - 1; i >= 0; --i) {
//            for (int j = 0; j <= i; ++j) {
//                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
//            }
//        }
//
//        return dp[0];
//    }
//};

//// 动态规划 + 空间优化 + 自顶向下
//class Solution {
//public:
//    int minimumTotal(vector<vector<int>> &triangle) {
//        int n = triangle.size();
//        vector<int> dp(n);
//        dp[0] = triangle[0][0];
//        for (int i = 1; i < n; ++i) {
//            dp[i] = dp[i - 1] + triangle[i][i];
//            for (int j = i - 1; j > 0; --j) {
//                dp[j] = min(dp[j - 1], dp[j]) + triangle[i][j];
//            }
//            dp[0] += triangle[i][0];
//        }
//
//        return *min_element(dp.begin(), dp.end());
//    }
//};

// 动态规划 + 空间优化（原地修改） + 自顶向下
class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int n = triangle.size();
        int minT = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            triangle[i][0] += triangle[i - 1][0];
            minT = triangle[i][0];
            for (int j = 1; j <= i; ++j) {
                triangle[i][j] += j == i ? triangle[i - 1][j - 1] : min(triangle[i - 1][j - 1], triangle[i - 1][j]);
                if (minT > triangle[i][j]) minT = triangle[i][j];
            }
        }
        return minT;
    }
};


int main(int argc, char *argv[]) {
    vector<vector<int>> triangle{{2},
                                 {3, 4},
                                 {6, 5, 7},
                                 {4, 1, 8, 3}};
    cout << Solution().minimumTotal(triangle) << endl;
    return 0;
}