//
// Created by 谢卓 on 2021/3/3.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int removeDuplicates(vector<int>& nums) {
        auto n = nums.size();
        if(n == 0) return 0;

        int i = 0, j = 0;
        while (j < n) {
            if(nums[i] < nums[j]) {
                nums[++i] = nums[j++];
            } else {
                j++;
            }
        }

        return i + 1;
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int len = Solution::removeDuplicates(nums);
    cout << len << endl;

    for (int i = 0; i < len; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}