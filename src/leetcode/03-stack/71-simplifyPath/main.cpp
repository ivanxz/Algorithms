//
// Created by 谢卓 on 2021/3/7.
//

#include <iostream>
#include <stack>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        path += "/";
        stack<string> st;
        string dir;
        for (auto c : path) {
            if (c == '/') {
                if (dir == ".." && !st.empty()) {
                    st.pop();
                } else if (dir != ".." && dir != "." && !dir.empty()) {
                    st.push(dir);
                }
                dir.clear();
            } else {
                dir += c;
            }
        }
        string res;
        while (!st.empty()) {
            auto t = st.top();
            st.pop();
            res += string(t.rbegin(), t.rend()) + "/";
        }
        reverse(res.begin(), res.end());
        if (res.empty()) res = "/";
        return res;
//        string res;
//        vector<string> tmp = split(path, '/');
//        for (const string& s:tmp) {
//            res += "/";
//            res += s;
//        }
//        return res.empty() ? "/" : res;
    }
//
//private:
//    vector<string> split(const string &s, char delemiter) {
//        vector<string> tokens;
//        string token;
//        istringstream tokenStream(s);
//        while (getline(tokenStream, token, delemiter)) {
//            if (token.empty() || token == "." || (token == ".." && tokens.empty()))
//                continue;
//            else if (token == ".." && !tokens.empty())
//                tokens.pop_back();
//            else
//                tokens.push_back(token);
//        }
//        return tokens;
//    }
};

int main(int argc, char *argv[]) {
    cout << Solution().simplifyPath("/a/./b/../../c/") << endl;
    return 0;
}