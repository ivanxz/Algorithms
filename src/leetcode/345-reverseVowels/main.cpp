//
// Created by 谢卓 on 2021/3/4.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static string reverseVowels(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (!isVowels(s[l])) {
                l++;
            } else if (!isVowels(s[r])) {
                r--;
            } else {
                swap(s[l], s[r]);
                l++;
                r--;
            }
        }

        return s;
    }

private:
    static bool isVowels(char c) {
        switch (c) {
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'u':
            case 'U':
                return true;
            default:
                return false;
        }
    }
};

int main(int argc, char *argv[]) {
    string s = "hello";
    cout << Solution::reverseVowels(s) << endl;
    return 0;
}