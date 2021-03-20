//
// Created by 谢卓 on 2021/3/19.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> ans;
    void dfs(const string &s, int cnt, int index, string &str) {
        if (cnt == 4 || index == s.size()) {
            if (cnt == 4 && index == s.size())
                ans.emplace_back(str.substr(0, str.size() - 1));
            return;
        }

        for (int i = 1; i <= 3; i++) {
            if (index + i > s.size()) return;
            if (s[index] == '0' && i != 1) return; // 去除前导0的情况
            if (i == 3 && s.substr(index, i) > "255") return; // 去除最后一位大于255
            str += s.substr(index, i);
            str.push_back('.');
            dfs(s, cnt + 1, index + i, str);
            str = str.substr(0, str.size() - i - 1);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        string str;
        dfs(s, 0, 0, str);
        return ans;
    }
};

int main(int argc, char *argv[]) {
    vector<string> res = Solution().restoreIpAddresses("0000");
    for (auto &str : res) {
        cout << str << " ";
    }
    cout << endl;
    return 0;
}