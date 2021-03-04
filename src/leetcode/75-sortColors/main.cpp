//
// Created by 谢卓 on 2021/3/4.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static void sortColors(vector<int>& nums) {
        auto n = nums.size();
        int zero = -1, two = n, i = 0;
        while (i < two) {
            if (1 == nums[i]) {
                i++;
            } else if (2 == nums[i]) {
                swap(nums[--two], nums[i]);
            } else {
                swap(nums[++zero], nums[i++]);
            }
        }
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums = {2,0,2,1,1,0};
    Solution::sortColors(nums);
    for (auto k: nums) {
        cout << k << " ";
    }
    cout << endl;
    return 0;
}