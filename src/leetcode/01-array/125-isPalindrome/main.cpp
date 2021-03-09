//
// Created by 谢卓 on 2021/3/4.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string newStr;
        for (auto c: s) {
            if (isalnum(c)) {
                newStr.push_back(tolower(c));
            }
        }

        int l = 0, r = newStr.size() - 1;
        while (l < r) {
            if (newStr[l] != newStr[r]) {
                return false;
            }

            l++;
            r--;
        }

        return true;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string s = "A man, a plan, a canal: Panama";
    cout << solution.isPalindrome(s) << endl;
    return 0;
}