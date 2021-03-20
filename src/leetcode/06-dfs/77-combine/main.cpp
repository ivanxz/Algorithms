//
// Created by 谢卓 on 2021/3/19.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        if (n == 0 || k == 0 || k > n)
            return res;
        vector<int> path;
        dfs(n, k, 1, path);
        return res;
    }

private:
    vector<vector<int>> res;

    void dfs(int n, int k, int index, vector<int>& path) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }

        for (int i = index; i <= n - (k - path.size()) + 1; ++i) {
            path.emplace_back(i);
            dfs(n, k, i + 1, path);
            path.pop_back();
        }
    }
};

int main(int argc, char *argv[]) {
    vector<vector<int>> res = Solution().combine(4, 2);
    for (auto &vec : res) {
        for (auto k : vec) {
            cout << k << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}