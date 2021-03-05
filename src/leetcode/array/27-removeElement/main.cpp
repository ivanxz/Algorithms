//
// Created by 谢卓 on 2021/3/3.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int removeElement(vector<int>& nums, int val) {
        int l = 0, r = nums.size() - 1;
        while (r >= l) {
            if(nums[l] == val)
                swap(nums[l], nums[r--]);
            else
                l++;
        }

        return l;
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums = {3,2,2,3};
    int val = 3;
    int len = Solution::removeElement(nums, val);
    cout << len << endl;

    for (int i = 0; i < len; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}