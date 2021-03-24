//
// Created by 谢卓 on 2021/3/23.
//

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;

        int n = nums.size();
        int C = sum / 2;
        vector<bool> dp(C + 1, false);
        for (int i = 0; i <= C; ++i) {
            dp[i] = nums[0] == i;
        }

        for (int i = 1; i < n; ++i) {
            for (int j = C; j >= nums[i]; --j) {
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }

        return dp[C];
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums{1, 1};
    cout << Solution().canPartition(nums) << endl;
    return 0;
}