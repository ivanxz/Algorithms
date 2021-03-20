//
// Created by 谢卓 on 2021/3/19.
//

#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    vector<vector<int>> subsets(vector<int>& nums) {
//        vector<int> path;
//        for (int i = 0; i <= nums.size(); ++i) {
//            dfs(nums, i, 0, path);
//        }
//        return res;
//    }
//
//private:
//    vector<vector<int>> res;
//
//    void dfs(const vector<int>& nums, int count, int index, vector<int>& path) {
//        if (path.size() == count) {
//            res.emplace_back(path);
//            return;
//        }
//
//        for (int i = index; i < nums.size(); ++i) {
//            path.emplace_back(nums[i]);
//            dfs(nums, count, i + 1, path);
//            path.pop_back();
//        }
//    }
//};

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        dfs(nums, 0, path);
        return ans;
    }

private:
    vector<vector<int>> ans;
    void dfs(const vector<int>& nums, int index, vector<int>& path) {
        if (index == nums.size()) {
            ans.push_back(path);
            return;
        }

        path.push_back(nums[index]);
        dfs(nums, index + 1, path);
        path.pop_back();
        dfs(nums, index + 1, path);
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = Solution().subsets(nums);
    for (auto &vec : res) {
        for (auto k : vec) {
            cout << k << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}