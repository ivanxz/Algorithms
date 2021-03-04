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
        if (n == 0) return 0;

        int j = 1, count = 1;
        for (int i = 1; i < n; ++i) {
            if(nums[i] == nums[i - 1]){
                count++;
            } else {
                count = 1;
            }

            if(count <= 2) {
                nums[j++] = nums[i];
            }
        }

        return j;
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums = {1,1,1,2,2,3};
    int len = Solution::removeDuplicates(nums);
    cout << len << endl;

    for (int i = 0; i < len; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}