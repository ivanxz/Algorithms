//
// Created by 谢卓 on 2021/3/19.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {

    }
};

int main(int argc, char *argv[]) {
    vector<string> res = Solution().readBinaryWatch(1);
    for (auto& str : res) {
        cout << str << " ";
    }
    cout << endl;
    return 0;
}