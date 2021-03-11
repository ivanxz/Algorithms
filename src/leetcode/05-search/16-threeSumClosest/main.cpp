//
// Created by 谢卓 on 2021/3/3.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int n = (int) nums.size();
        int closestSum = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n - 2; ++i) {
            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (abs(sum - target) < abs(closestSum - target)) {
                    closestSum = sum;
                }

                if (sum < target) l++;
                else if (sum > target) r--;
                else {
                    return target;
                }
            }
        }

        return closestSum;
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums = {1,2,4,8,16,32,64,128};
    int target = 82;
    cout << Solution().threeSumClosest(nums, target) << endl;
    return 0;
}