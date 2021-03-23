//
// Created by 谢卓 on 2021/3/23.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {

    }
};

int main(int argc, char *argv[]) {
    vector<string> wordDict;
    cout << Solution().wordBreak("leetcode", wordDict) << endl;
    for_each(wordDict.begin(), wordDict.end(), [](const string &item) { cout << item << " "; });
    cout << endl;
    return 0;
}