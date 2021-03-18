//
// Created by 谢卓 on 2021/3/16.
//

#include <iostream>
#include <queue>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

};

int main(int argc, char *argv[]) {
    cout << endl;
    return 0;
}