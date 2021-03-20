//
// Created by 谢卓 on 2021/3/19.
//

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        dfs(k, n, 1, path);
        return res;
    }

private:
    vector<vector<int>> res;

    void dfs(int k, int target, int index, vector<int> &path) {
        if (path.size() == k) {
            if (target == 0)
                res.emplace_back(path);
            return;
        }

        for (int i = index; i <= 9 && i <= target; ++i) {
            path.emplace_back(i);
            dfs(k, target - i, i + 1, path);
            path.pop_back();
        }
    }
};

int main(int argc, char *argv[]) {
    vector<vector<int>> res = Solution().combinationSum3(2, 18);
    for (auto &vec : res) {
        for (auto k : vec) {
            cout << k << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}