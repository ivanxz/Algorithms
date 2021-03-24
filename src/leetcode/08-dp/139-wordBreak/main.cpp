//
// Created by 谢卓 on 2021/3/23.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> uds;
        for (auto &word: wordDict) {
            uds.insert(word);
        }

        int n = s.length();
        auto dp = vector<bool>(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && uds.find(s.substr(j, i - j)) != uds.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};

int main(int argc, char *argv[]) {
    vector<string> wordDict{"leet", "code"};
    cout << Solution().wordBreak("leetcode", wordDict) << endl;
    for_each(wordDict.begin(), wordDict.end(), [](const string &item) { cout << item << " "; });
    cout << endl;
    return 0;
}