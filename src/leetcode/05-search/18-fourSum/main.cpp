//
// Created by 谢卓 on 2021/3/3.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 4) return res;

        sort(nums.begin(), nums.end());
        if (nums[0] > 0) return res;

        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            if (nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3] < target) continue;

            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
                if (nums[i] + nums[j] + nums[n - 1] + nums[n - 2] < target) continue;
                int l = j + 1;
                int r = n - 1;
                while (l < r) {
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum < target) l++;
                    else if (sum > target) r--;
                    else {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while (l < r && nums[l] == nums[l + 1]) l++;
                        l++;
                        while (l < r && nums[r] == nums[r - 1]) r--;
                        r--;
                    }
                }
            }
        }

        return res;
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> res = Solution().fourSum(nums, target);
    for (auto &vec: res) {
        for (auto k : vec) {
            cout << k << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}