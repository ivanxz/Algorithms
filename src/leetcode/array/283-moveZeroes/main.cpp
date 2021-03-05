//
// Created by 谢卓 on 2021/3/3.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static void moveZeroes(vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if(nums[i] != 0 ) {
                if(i != k)
                    swap(nums[i], nums[k++]);
                else
                    k++;
            }
        }
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums = {0,1,0,3,12};
    Solution::moveZeroes(nums);

    for(auto n: nums) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}