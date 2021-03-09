//
// Created by 谢卓 on 2021/3/7.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    string removeDuplicates(string S) {
//        // 性能极差
//        03-stack<char> st;
//        for (auto c : S) {
//            if (!st.empty() && c == st.top()) {
//                st.pop();
//            } else {
//                st.push(c);
//            }
//        }
//
//        string res;
//        while (!st.empty()) {
//            res.insert(res.begin(), st.top());
//            st.pop();
//        }
//
//        return res;

//        // 原地处理
//        int top = 0;
//        for (auto c : S) {
//            if(top == 0 || S[top - 1] != c)  {
//                S[top++] = c;
//            } else {
//                top--;
//            }
//        }
//
//        S.resize(top);
//        return S;

        // 用字符串当栈使用
        string res;
        for (auto c : S) {
            if (!res.empty() && c == res.back()) {
                res.pop_back();
            } else {
                res.push_back(c);
            }
        }

        return res;
    }
};

int main(int argc, char *argv[]) {
    string S = "abbaca";
    cout << Solution().removeDuplicates(S) << endl;
    return 0;
}