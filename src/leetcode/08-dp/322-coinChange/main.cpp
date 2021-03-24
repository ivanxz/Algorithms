//
// Created by 谢卓 on 2021/3/23.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (coin <= i) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

//// 贪心+回溯+剪枝
//class Solution {
//public:
//    void coinChange(vector<int> &coins, int amount, int c_index, int count, int &ans) {
//        if (amount == 0) {
//            ans = min(ans, count);
//            return;
//        }
//        if (c_index == coins.size()) return;
//
//        for (int k = amount / coins[c_index]; k >= 0 && k + count < ans; k--) {
//            coinChange(coins, amount - k * coins[c_index], c_index + 1, count + k, ans);
//        }
//    }
//
//    int coinChange(vector<int> &coins, int amount) {
//        if (amount == 0) return 0;
//        sort(coins.rbegin(), coins.rend());
//        int ans = INT_MAX;
//        coinChange(coins, amount, 0, 0, ans);
//        return ans == INT_MAX ? -1 : ans;
//    }
//};

int main(int argc, char *argv[]) {
    vector<int> coins{1, 2, 5};
    cout << Solution().coinChange(coins, 11) << endl;
    return 0;
}