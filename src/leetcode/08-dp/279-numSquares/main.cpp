//
// Created by 谢卓 on 2021/3/23.
//

#include <iostream>
#include <vector>

using namespace std;

//// 递归+记忆化搜索
//class Solution {
//private:
//    vector<int> memo;
//    int max3(int a, int b, int c) {
//        return max(a, max(b, c));
//    }
//
//    // 将n分割（至少分割成两部分），最大乘积
//    int breaknteger(int n) {
//        if (n == 1) return 1;
//
//        if (memo[n] != -1)
//            return memo[n];
//
//        int res = -1;
//        for (int i = 1; i <= n - 1; ++i) {
//            res = max3(res, i * (n - i), i * breaknteger(n - i));
//        }
//
//        memo[n] = res;
//        return res;
//    }
//public:
//    int integerBreak(int n) {
//        memo = vector<int>(n + 1, -1);
//        return breaknteger(n);
//    }
//};

// 动态规划
class Solution {
private:
    int max3(int a, int b, int c) {
        return max(a, max(b, c));
    }

public:
    int numSquares(int n) {
        auto dp = vector<int>(n + 1, -1);
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            // 求解dp[i]
            for (int j = 1; j <= i - 1; ++j) {
                // j + (i - j)
                dp[i] = max3(dp[i], j * (i - j), j * dp[i - j]);
            }
        }

        return dp[n];
    }
};

int main(int argc, char *argv[]) {
    cout << Solution().numSquares(12) << endl;
    return 0;
}