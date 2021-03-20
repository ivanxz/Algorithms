//
// Created by 谢卓 on 2021/3/19.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        dfs(s, 0);
        return res;
    }

private:
    vector<vector<string>> res;

    void dfs(const string& s, int index) {


        for (int i = index; i < s.length(); ++i) {

        }
    }

    bool isMirror(const string& s) {
        if (1 == s.length()) return true;

        int l = 0, r = s.length() - 1;
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }

        return true;
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