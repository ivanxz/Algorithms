//
// Created by 谢卓 on 2021/3/23.
//

#include <iostream>
#include <vector>

using namespace std;

// 动态规划
class Solution {

public:
    int numSquares(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            dp[i] = i;
            for (int j = 1; i - j * j >= 0 ; ++j) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }

        return dp[n];
    }
};

int main(int argc, char *argv[]) {
    cout << Solution().numSquares(12) << endl;
    return 0;
}