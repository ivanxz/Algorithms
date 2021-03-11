//
// Created by 谢卓 on 2021/3/3.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> res;
        unordered_map<string, int> record;
        for (int i = 0; i < strs.size(); ++i) {
            string str = strs[i];
            sort(str.begin(), str.end());
            if (!record.count(str)) {
                vector<string> vec = {strs[i]};
                res.push_back(vec);
                record[str] = res.size() - 1;
            } else {
                res[record[str]].push_back(strs[i]);
            }
        }

        return res;
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