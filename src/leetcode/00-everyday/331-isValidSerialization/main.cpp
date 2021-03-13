//
// Created by 谢卓 on 2021/3/12.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = preorder.length();
        stack<char> stk;
        stk.push(1);
        int i = 0;
        while (i < n) {
            if (stk.empty()) return false;
            if (',' == preorder[i]) i++;
            else if ('#' == preorder[i]) {
                stk.top() -= 1;
                if (0 == stk.top()) {
                    stk.pop();
                }
                i++;
            } else {
                while (i < n && preorder[i] != ',') i++;
                stk.top() -= 1;
                if (0 == stk.top()) {
                    stk.pop();
                }
                stk.push(2);
            }
        }

        return stk.empty();
    }
};

int main(int argc, char *argv[]) {
    string preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    cout << Solution().isValidSerialization(preorder) << endl;
    return 0;
}