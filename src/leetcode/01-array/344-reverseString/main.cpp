//
// Created by 谢卓 on 2021/3/4.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static void reverseString(vector<char> &s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            swap(s[l++], s[r--]);
        }
    }
};

int main(int argc, char *argv[]) {
    vector<char> s = {'H', 'a', 'n', 'n', 'a', 'h'};
    Solution::reverseString(s);
    for (auto c: s) {
        cout << c << " ";
    }
    cout << endl;
    return 0;
}