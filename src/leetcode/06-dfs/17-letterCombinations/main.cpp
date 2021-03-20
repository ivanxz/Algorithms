//
// Created by 谢卓 on 2021/3/13.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    const string letterMap[10]{
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
    };
    vector<string> res;

    void findCombinations(const string &digits, int index, const string &path) {
        if (index == digits.length()) {
            res.push_back(path);
            return;
        }

        char c = digits[index];
        string letters = letterMap[c - '0'];
        for (char letter : letters) {
            findCombinations(digits, index + 1, path + letter);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) return res;
        findCombinations(digits, 0, "");
        return res;
    }
};

int main(int argc, char *argv[]) {
    vector<string> res = Solution().letterCombinations("23");
    for (auto &str : res) {
        cout << str << " ";
    }
    cout <<  endl;
    return 0;
}