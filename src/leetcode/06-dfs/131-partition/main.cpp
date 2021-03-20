//
// Created by 谢卓 on 2021/3/19.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        n = s.size();
        f.assign(n, vector<int>(n));
        vector<string> path;
        dfs(s, 0, path);
        return res;
    }

private:
    vector<vector<int>> f;
    vector<vector<string>> res;
    int n;

    void dfs(const string &s, int i, vector<string>& path) {
        if (i == n) {
            res.push_back(path);
            return;
        }
        for (int j = i; j < n; ++j) {
            if (isPalindrome(s, i, j) == 1) {
                path.push_back(s.substr(i, j - i + 1));
                dfs(s, j + 1, path);
                path.pop_back();
            }
        }
    }

    // 记忆化搜索中，f[i][j] = 0 表示未搜索，1 表示是回文串，-1 表示不是回文串
    int isPalindrome(const string &s, int i, int j) {
        if (f[i][j]) {
            return f[i][j];
        }
        if (i >= j) {
            return f[i][j] = 1;
        }

        return f[i][j] = (s[i] == s[j] ? isPalindrome(s, i + 1, j - 1) : -1);
    }
};

int main(int argc, char *argv[]) {
    vector<vector<string>> res = Solution().partition("aab");
    for (auto &vec : res) {
        for (auto &str : vec) {
            cout << str << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}