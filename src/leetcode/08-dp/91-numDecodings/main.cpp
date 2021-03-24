//
// Created by 谢卓 on 2021/3/23.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        if (s[0] ==  '0') return 0;
        int n = s.length();
        int pre = 1, cur = 1;
        for (int i = 1; i < n; ++i) {
            int temp = cur;
            if (s[i] == '0')
                if (s[i - 1] == '1' || s[i - 1] == '2') cur = pre;
                else return 0;
            else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6'))
                cur = cur + pre;
            pre = temp;
        }

        return cur;
    }
};

int main(int argc, char *argv[]) {
    cout <<  Solution().numDecodings("226") <<endl;
    return 0;
}