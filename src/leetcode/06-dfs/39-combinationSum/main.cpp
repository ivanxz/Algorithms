//
// Created by 谢卓 on 2021/3/19.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        dfs(candidates, target, 0, path);
        return res;
    }

private:
    vector<vector<int>> res;

    void dfs(const vector<int>& candidates, int target, int index, vector<int>& path) {
        if (index == candidates.size()) return;
        if (0 == target) {
            res.emplace_back(path);
            return;
        }

        dfs(candidates, target, index + 1, path);
        if (target - candidates[index] >= 0) {
            path.emplace_back(candidates[index]);
            dfs(candidates, target - candidates[index], index, path);
            path.pop_back();
        }
    }
};

int main(int argc, char *argv[]) {
    vector<int> candidates = {2, 3, 5};
    vector<vector<int>> res = Solution().combinationSum(candidates, 8);
    for (auto &vec : res) {
        for (auto k : vec) {
            cout << k << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}