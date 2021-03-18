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
    TreeNode *deleteNode(TreeNode *root, int key) {
//        if (root == nullptr)
//            return nullptr;
//
//        if (key > root->val)
//            root->right = deleteNode(root->right, key);
//        else if (key < root->val)
//            root->left = deleteNode(root->left, key);
//        else {
//            if (root->left == nullptr && root->right == nullptr)
//                root = nullptr;
//            else if (root->right != nullptr) {
//                root->val = successor(root);
//                root->right = deleteNode(root->right, root->val);
//            } else {
//                root->val = predecessor(root);
//                root->left = deleteNode(root->left, root->val);
//            }
//        }
//
//        return root;
        if (root == nullptr)
            return nullptr;
        if (key < root->val)
            root->left = deleteNode(root->left, key);
        else if (key > root->val)
            root->right = deleteNode(root->right, key);
        else {
            if (root->left == nullptr && root->right == nullptr)
                return nullptr;
            else if (root->right == nullptr)
                return root->left;
            else if (root->left == nullptr)
                return root->right;
            else {
                TreeNode *temp = root->right;
                while (temp->left)
                    temp = temp->left;
                root->val = temp->val;
                root->right = deleteNode(root->right, root->val);
            }
        }

        return root;
    }

    int successor(TreeNode *root) {
        root = root->right;
        while (root->left != nullptr)
            root = root->left;

        return root->val;
    }

    int predecessor(TreeNode *root) {
        root = root->left;
        while (root->right != nullptr)
            root = root->right;
        return root->val;
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

TreeNode *stringToTreeNode(string input) {
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
    TreeNode *root = new TreeNode(stoi(item));
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode *node = nodeQueue.front();
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

string treeNodeToString(TreeNode *root) {
    if (root == nullptr) {
        return "[]";
    }

    string output = "";
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode *node = q.front();
        q.pop();

        if (node == nullptr) {
            output += "null, ";
            continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode *root = stringToTreeNode(line);
        getline(cin, line);
        int key = stringToInteger(line);

        TreeNode *ret = Solution().deleteNode(root, key);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}