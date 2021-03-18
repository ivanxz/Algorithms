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
//    int countNodes(TreeNode* root) {
//        if (root == nullptr)
//            return 0;
//
//        if (root->left == nullptr)
//            return 1;
//
//        if (root->right == nullptr)
//            return countNodes(root->left) + 1;
//
//        return countNodes(root->left) + countNodes(root->right) + 1;
//    }
//    int countNodes(TreeNode* root) {
//        if (root == nullptr) {
//            return 0;
//        }
//
//        int level = 0;
//        TreeNode* node = root;
//        while (node->left != nullptr) {
//            level++;
//            node = node->left;
//        }
//
//        int low = 1 << level, high = (1 << (level + 1)) - 1;
//        while (low < high) {
//            int mid = (high - low + 1) / 2 + low;
//            if (exists(root, level, mid)) {
//                low = mid;
//            } else {
//                high = mid - 1;
//            }
//        }
//        return low;
//    }
//
//    bool exists(TreeNode* root, int level, int k) {
//        int bits = 1 << (level - 1);
//        TreeNode* node = root;
//        while (node != nullptr && bits > 0) {
//            if (!(bits & k)) {
//                node = node->left;
//            } else {
//                node = node->right;
//            }
//            bits >>= 1;
//        }
//        return node != nullptr;
//    }

    int countNodes(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int left = countLevel(root->left);
        int right =  countLevel(root->right);
        return left == right ? countNodes(root->right) + (1 << left) : countNodes(root->left) + (1 << right);
    }

    int countLevel(TreeNode* root) {
        int level = 0;

        while (root != nullptr) {
            root = root->left;
            level++;
        }

        return level;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);

        int ret = Solution().countNodes(root);
        cout << ret << endl;
    }
    return 0;
}