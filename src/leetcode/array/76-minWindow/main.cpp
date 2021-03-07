//
// Created by 谢卓 on 2021/3/3.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    static string minWindow(string s, string t) {
        int sn = s.size();
        int tn = t.size();
        if (0 == sn || 0 == tn || tn > sn)
            return "";

        unordered_map<char, int> window, need;
        for (auto c: t)
            need[c]++;

        int l = 0, r = 0, count = 0;
        int begin = 0, minLen = sn + 1;
        // [l, r)
        while (r < sn) {
            char c = s[r++];
            window[c]++;

            if (need.count(c) && window[c] <= need[c])
                count++;

            while (count == tn) {
                int len = r - l;
                if(len < minLen) {
                    minLen = len;
                    begin = l;
                }

                char temp = s[l++];
                window[temp]--;
                if (need.count(temp) && window[temp] < need[temp]) {
                    count--;
                }
            }
        }

        if (minLen == sn + 1)
            return "";

        return s.substr(begin, minLen);
    }
};

int main(int argc, char *argv[]) {
    string s = "ADOBECODEBANC", t = "ABC";
    cout << Solution::minWindow(s, t) << endl;
    return 0;
}