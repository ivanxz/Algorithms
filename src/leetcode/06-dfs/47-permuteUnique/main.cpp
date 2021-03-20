//
// Created by 谢卓 on 2021/3/19.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.empty()) return res;
        used = vector<bool>(nums.size(), false);
        sort(nums.begin(), nums.end());
        vector<int> path;
        dfs(nums, 0, path);
        return res;
    }

private:
    vector<vector<int>> res;
    vector<bool> used;

    void dfs(const vector<int>& nums, int index, vector<int>& path) {
        if (index == nums.size()) {
            res.emplace_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])) {
                continue;
            }

            path.emplace_back(nums[i]);
            used[i] = true;
            dfs(nums, index + 1, path);
            path.pop_back();
            used[i] = false;
        }
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums = {3, 3, 0, 3};
    vector<vector<int>> res = Solution().permuteUnique(nums);
    for (auto &vec : res) {
        for (auto k : vec) {
            cout << k << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}