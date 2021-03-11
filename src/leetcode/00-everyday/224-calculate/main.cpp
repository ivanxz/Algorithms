//
// Created by 谢卓 on 2021/3/7.
//

#include <iostream>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

class Solution {
private:
    // 单栈
    int calculate1(const string &s) {
        stack<int> st;
        int sign = 1, res = 0;
        int length = s.length();
        for (int i = 0; i < length; i++) {
            char ch = s[i];
            if (isdigit(ch)) {
                int cur = ch - '0';
                while (i + 1 < length && isdigit(s[i + 1])) {
                    i = i + 1;
                    int a = s[i] - '0';
                    cur = cur * 10 + a;
                }
                res = res + sign * cur;
            } else if (ch == '+') {
                sign = 1;
            } else if (ch == '-') {
                sign = -1;
            } else if (ch == '(') {
                st.push(res);
                res = 0;
                st.push(sign);
                sign = 1;
            } else if (ch == ')') {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                res = a * res + b;
            }
        }

        return res;
    }
public:
    int calculate(string s) {
        return calculate1(s);
    }
};

int main(int argc, char *argv[]) {
    string s = "- (3 + (4 + 5))";
    //string s = "1-(5)";
    cout << Solution().calculate(s) << endl;
    return 0;
}