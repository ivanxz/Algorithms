//
// Created by 谢卓 on 2021/3/23.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int n = prices.size();
        int f0 = -prices[0];
        int f1 = 0;
        int f2 = 0;
        for (int i = 1; i < n; ++i) {
            tie(f0, f1, f2) = make_tuple(max(f0, f2 - prices[i]), f0 + prices[i], max(f1, f2));
        }

        return max(f1, f2);

//        // dp[i][0]: 手上持有股票的最大收益
//        // dp[i][1]: 手上不持有股票，并且处于冷冻期中的累计最大收益
//        // dp[i][2]: 手上不持有股票，并且不在冷冻期中的累计最大收益
//        vector<vector<int>> dp(n, vector<int>(3));
//        dp[0][0] = -prices[0];
//        for (int i = 1; i < n; ++i) {
//            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
//            dp[i][1] = dp[i - 1][0] + prices[i];
//            dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]);
//        }
//
//        return max(dp[n - 1][1], dp[n - 1][2]);
    }
};

int main(int argc, char *argv[]) {
    vector<int> prices{1, 2, 3, 0, 2};
    cout << Solution().maxProfit(prices) << endl;
    return 0;
}