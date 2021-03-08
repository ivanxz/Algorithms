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
    ListNode *sortList(ListNode *head) {
        if (head == nullptr) return head;

        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head;

        ListNode *tailNode = head;
        ListNode *curNode = head->next;
        while (curNode != nullptr) {

        }

        return dummyNode->next;
    }
};

int main(int argc, char *argv[]) {
    int arr[] = {4, 2, 1, 3};
    int n = sizeof(arr) / sizeof(int);

    ListNode *head = createListNode(arr, n);
    printListNode(head);

    ListNode *retNode = Solution().sortList(head);
    printListNode(retNode);

    deleteListNode(retNode);
    return 0;
}