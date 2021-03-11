//
// Created by 谢卓 on 2021/3/3.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {

    }
};

int main(int argc, char *argv[]) {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = Solution().groupAnagrams(strs);
    for (const auto &vec: res) {
        for (const string &k : vec) {
            cout << k << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}