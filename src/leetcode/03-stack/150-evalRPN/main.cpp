//
// Created by 谢卓 on 2021/3/7.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> st;
        for (const string &s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();

                if (s == "+") st.push(num2 + num1);
                if (s == "-") st.push(num2 - num1);
                if (s == "*") st.push(num2 * num1);
                if (s == "/") st.push(num2 / num1);
            } else {
                st.push(stoi(s));
            }
        }

        int res = st.top();
        st.pop();
        return res;
    }
};

int main(int argc, char *argv[]) {
    vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << Solution().evalRPN(tokens) << endl;
    return 0;
}