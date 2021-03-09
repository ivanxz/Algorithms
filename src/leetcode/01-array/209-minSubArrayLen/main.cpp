//
// Created by 谢卓 on 2021/3/4.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int minSubArrayLen(int target, vector<int> &nums) {
        int l = 0, r = -1;
        int ans = nums.size() + 1;
        int sum = 0;
        while (l < nums.size()) {
            if (r + 1 < nums.size() && sum < target)
                sum += nums[++r];
            else
                sum -= nums[l++];

            if (sum >= target)
                ans = min(ans, r - l + 1);
        }

        if (ans == nums.size() + 1)
            return 0;

        return ans;
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;
    cout << Solution::minSubArrayLen(target, nums) << endl;
    return 0;
}