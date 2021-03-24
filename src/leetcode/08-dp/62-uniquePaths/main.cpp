//
// Created by 谢卓 on 2021/3/23.
//

#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    int uniquePaths(int m, int n) {
//        vector<vector<int>> dp(m, vector<int>(n));
//
//        for (int i = 0; i < m; ++i) {
//            dp[i][0] = 1;
//        }
//
//        for (int j = 0; j < n; ++j) {
//            dp[0][j] = 1;
//        }
//
//        for (int i = 1; i < m; ++i) {
//            for (int j = 1; j < n; ++j) {
//                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//            }
//        }
//
//        return dp[m - 1][n - 1];
//    }
//};

class Solution {
public:
    int uniquePaths(int m, int n) {
        int mm = min(m, n);
        int nn = max(m, n);
        vector<int> dp(mm, 1);

        for (int i = 1; i < nn; ++i) {
            for (int j = 1; j < mm; ++j) {
                dp[j] += dp[j - 1];
            }
        }

        return dp[mm - 1];
    }
};

int main(int argc, char *argv[]) {
    cout << Solution().uniquePaths(3, 7) << endl;
    return 0;
}