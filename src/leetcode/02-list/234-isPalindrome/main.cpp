//
// Created by 谢卓 on 2021/3/7.
//

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *createListNode(int arr[], int n) {
    if (n == 0)
        return nullptr;

    ListNode *head = new ListNode(arr[0]);
    ListNode *curNode = head;
    for (int i = 1; i < n; ++i) {
        curNode->next = new ListNode(arr[i]);
        curNode = curNode->next;
    }

    return head;
}

void printListNode(ListNode *head) {
    ListNode *curNode = head;
    while (curNode != nullptr) {
        cout << curNode->val << " -> ";
        curNode = curNode->next;
    }

    cout << "NULL" << endl;
}

void deleteListNode(ListNode *head) {
    ListNode *curNode = head;
    while (curNode != nullptr) {
        ListNode* delNode = curNode;
        curNode = curNode->next;
        delete delNode;
    }
}

class Solution {
public:
    bool isPalindrome(ListNode *head) {
//
//        // 使用栈性能极差
//        vector<int> vec;
//        while (head != nullptr) {
//            vec.push_back(head->val);
//            head = head->next;
//        }
//
//        int l = 0, r = (int)vec.size() - 1;
//        while (l < r) {
//            if(vec[l++] != vec[r--]) {
//                return false;
//            }
//        }
//
//        return true;

        // 快慢双指针
        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        // 定义快慢两个指针
        ListNode *fast = head;
        ListNode *slow = head;

        ListNode *first = new ListNode(-1);
        ListNode *temp;
        // 找中点的时候完成交换
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            temp = slow->next;
            slow->next = first->next;
            first->next = slow;
            slow = temp;
        }

        // 奇数个链表
        if (fast != nullptr) {
            slow = slow->next;
        }

        while (slow != nullptr) {
            if (slow->val != first->next->val) {
                return false;
            }

            slow = slow->next;
            first = first->next;
        }

        return true;
    }
};

int main(int argc, char *argv[]) {
    int arr[] = {1, 2, 2, 1};
    int n = sizeof(arr) / sizeof(int);

    ListNode *head = createListNode(arr, n);
    printListNode(head);

    cout << Solution().isPalindrome(head) << endl;
    printListNode(head);

    deleteListNode(head);
    return 0;
}