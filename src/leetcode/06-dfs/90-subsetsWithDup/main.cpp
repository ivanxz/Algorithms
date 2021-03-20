//
// Created by 谢卓 on 2021/3/19.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> path;
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= nums.size(); ++i) {
            dfs(nums, i, 0, path);
        }
        return res;
    }

private:
    vector<vector<int>> res;

    void dfs(const vector<int>& nums, int count, int index, vector<int>& path) {
        if (path.size() == count) {
            res.emplace_back(path);
            return;
        }

        for (int i = index; i < nums.size(); ++i) {
            if (i > index && nums[i] == nums[i - 1]) continue;
            path.emplace_back(nums[i]);
            dfs(nums, count, i + 1, path);
            path.pop_back();
        }
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> res = Solution().subsetsWithDup(nums);
    for (auto &vec : res) {
        for (auto k : vec) {
            cout << k << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}