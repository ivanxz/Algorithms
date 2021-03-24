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
//    int tryRob(const vector<int> &nums, int index) {
//        if (index >= nums.size())
//            return 0;
//
//        if (memo[index] != -1)
//            return memo[index];
//
//        int res = 0;
//        for (int i = index; i < nums.size(); ++i) {
//            res = max(res, nums[i]+ tryRob(nums, i + 2));
//        }
//
//        memo[index] = res;
//        return res;
//    }
//public:
//    int rob(vector<int> &nums) {
//        if (nums.empty())
//            return 0;
//
//        memo = vector<int>(nums.size(), -1);
//        return tryRob(nums, 0);
//    }
//};

//// 动态规划
//class Solution {
//public:
//    int rob(vector<int> &nums) {
//        if (nums.empty())
//            return 0;
//
//        int n = nums.size();
//        // dp[i]为考虑抢劫nums[i...n-1]最大收益
//        vector<int> dp(n);
//        dp[n - 1] = nums[n - 1];
//        for (int i = n - 2; i >= 0; --i) {
//            for (int j = i; j < n; ++j) {
//                dp[i] = max(dp[i], nums[j] + (j + 2 < n ? dp[j + 2] : 0));
//            }
//        }
//
//        return dp[0];
//    }
//};

// 动态规划 + 空间优化
class Solution {
public:
    /**
     动态转移方程是：
        f(n)=max(nums[n]+f(n-2),f(n-1))
        prevMax:f(k-2)
        currMax:f(k-1)
        x:Ak
     */
    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int prevMax = 0;
        int currMax = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int temp = currMax;
            currMax = max(nums[i] + prevMax, currMax);
            prevMax = temp;
        }

        return currMax;
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums{1, 2, 3, 1};
    cout << Solution().rob(nums) << endl;
    return 0;
}