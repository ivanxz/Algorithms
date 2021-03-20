//
// Created by 谢卓 on 2021/3/19.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, path);
        return res;
    }

private:
    vector<vector<int>> res;

    void dfs(const vector<int> &candidates, int target, int index, vector<int> &path) {
        if (index == candidates.size()) {
            if (0 == target) res.emplace_back(path);
            return;
        }

        if (0 == target) {
            res.emplace_back(path);
            return;
        }

        for (int i = index; i < candidates.size(); ++i) {
            if (target < candidates[i]) continue;
            if (i > index && candidates[i] == candidates[i - 1]) continue;

            path.emplace_back(candidates[i]);
            dfs(candidates, target - candidates[i], i + 1, path);
            path.pop_back();
        }
    }
};

int main(int argc, char *argv[]) {
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>> res = Solution().combinationSum2(candidates, 8);
    for (auto &vec : res) {
        for (auto k : vec) {
            cout << k << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}