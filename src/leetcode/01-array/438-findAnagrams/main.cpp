//
// Created by 谢卓 on 2021/3/4.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    static vector<int> findAnagrams(string s, string p) {
        int pn = p.size();
        int sn = s.size();
        if (sn == 0 || sn < pn)
            return {};

        unordered_map<char, int> need, window;
        for (auto c : p)
            need[c]++;

        vector<int> res;
        int l = 0, r = 0;
        int vaild = 0;
        char c, t;
        while (r < sn) {
            c = s[r];
            r++;
            if (need.count(c))
            {
                window[c]++;
                if (need[c] == window[c])
                    vaild++;
            }

            while (vaild == need.size()) {
                if (r - l == pn)
                    res.push_back(l);

                t = s[l];
                l++;
                if (need.count(t)) {
                    if (window[t] == need[t])
                        vaild--;
                    window[t]--;
                }
            }
        }

        return res;
    }
};

int main(int argc, char *argv[]) {
    string s = "cbaebabacd", p = "abc";
    vector<int> ans = Solution::findAnagrams(s, p);
    cout << ans.size() << endl;
    for (auto i: ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}