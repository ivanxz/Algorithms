//
// Created by 谢卓 on 2021/3/19.
//

#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    vector<vector<int>> permute(vector<int>& nums) {
//        if (nums.empty()) return res;
//        used = vector<bool>(nums.size(), false);
//        vector<int> path;
//        dfs(nums, 0, path);
//        return res;
//    }
//
//private:
//    vector<vector<int>> res;
//    vector<bool> used;
//
//    void dfs(const vector<int>& nums, int index, vector<int>& path) {
//        if (index == nums.size()) {
//            res.emplace_back(path);
//            return;
//        }
//
//        for (int i = 0; i < nums.size(); ++i) {
//            if (!used[i]) {
//                path.emplace_back(nums[i]);
//                used[i] = true;
//                dfs(nums, index + 1, path);
//                path.pop_back();
//                used[i] = false;
//            }
//        }
//    }
//};

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) return res;
        dfs(nums, 0);
        return res;
    }

private:
    vector<vector<int>> res;

    void dfs(vector<int>& nums, int index) {
        if (index == nums.size()) {
            res.emplace_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); ++i) {
            swap(nums[i], nums[index]);
            dfs(nums, index + 1);
            swap(nums[i], nums[index]);
        }
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = Solution().permute(nums);
    for (auto &vec : res) {
        for (auto k : vec) {
            cout << k << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}