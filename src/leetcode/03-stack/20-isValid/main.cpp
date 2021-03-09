//
// Created by 谢卓 on 2021/3/7.
//

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto c : s) {
            if (!st.empty() && isMatch(st.top(), c))
                st.pop();
            else
                st.push(c);
        }

        return st.empty();
    }

private:
    bool isMatch(char s, char ins) {
        return s == '{' && ins == '}' || s == '(' && ins == ')' || s == '[' && ins == ']';
    }
};

int main(int argc, char *argv[]) {
    cout << Solution().isValid("(]") << endl;
    return 0;
}