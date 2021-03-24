//
// Created by 谢卓 on 2021/3/23.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int tryRob(const vector<int> &nums, int start, int end) {
        int prevMax = 0;
        int currMax = 0;
        for (int i = start; i < end; ++i) {
            int temp = currMax;
            currMax = max(nums[i] + prevMax, currMax);
            prevMax = temp;
        }

        return currMax;
    }
public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        return max(tryRob(nums, 0, n - 1), tryRob(nums, 1, n));
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums{2, 3, 2};
    cout << Solution().rob(nums) << endl;
    return 0;
}