//
// Created by 谢卓 on 2021/3/3.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = (int)nums.size();
        if (n < 3) return res;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) return res;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum < 0) l++;
                else if (sum > 0) r--;
                else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l + 1]) l++;
                    while (l < r && nums[r] == nums[r - 1]) r--;
                    l++;
                    r--;
                }
            }
        }

        return res;
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> res = Solution().threeSum(nums);
    for(auto & vec: res) {
        for (int k: vec) {
            cout << k << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}