//
// Created by 谢卓 on 2021/3/4.
//

#include <iostream>
using namespace std;

class Solution {
public:
    static int lengthOfLongestSubstring(string s) {
        char freq[256] = {0};
        int l = 0, r = -1;
        int ans = 0;
        while (l < s.size()) {
            if (r + 1 < s.size() && freq[s[r + 1]] == 0)
                freq[s[++r]]++;
            else
                freq[s[l++]]--;

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    string s = "abcabcbb";
    cout << Solution::lengthOfLongestSubstring(s) << endl;
    return 0;
}