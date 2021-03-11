//
// Created by 谢卓 on 2021/3/11.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        char sign = '+';
        int n = s.size();
        int d = 0, res = 0;
        for (int i = 0; i < n; ++i) {
            char ch = s[i];
            if (isdigit(ch)) {
                d = d * 10 - '0' + ch;  // 先减不然会int溢出
            }

            if ((ch < '0' && ch != ' ') || i == n - 1) {
                if (sign == '+') {
                    stk.push(d);
                } else if (sign == '-') {
                    stk.push(-d);
                } else if (sign == '*' || sign == '/') {
                    int tmp = sign == '*' ? stk.top() * d : stk.top() / d;
                    stk.pop();
                    stk.push(tmp);
                }

                sign = ch;
                d = 0;
            }

        }

        for (; !stk.empty(); stk.pop()) {
            res += stk.top();
        }

        return res;
    }
};

int main(int argc, char *argv[]) {
    string s = " 3+5 / 2 ";
    cout << Solution().calculate(s) << endl;
    return 0;
}