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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == nullptr) return head;

        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head;

        ListNode *preNode = dummyNode;
        ListNode *curNode = dummyNode;

        while (curNode->next != nullptr) {
            for (int i = 0; i < k && curNode != nullptr; ++i)
                curNode = curNode->next;

            if (curNode == nullptr)
                break;

            ListNode *startNode = preNode->next;
            ListNode *nextNode = curNode->next;
            curNode->next = nullptr;
            preNode->next = reverse(startNode);
            startNode->next = nextNode;
            preNode = startNode;
            curNode = preNode;
        }

        return dummyNode->next;
    }

private:
    ListNode *reverse(ListNode *head) {
        ListNode *preNode = nullptr;
        ListNode *curNode = head;
        while (curNode != nullptr) {
            ListNode *nextNode = curNode->next;
            curNode->next = preNode;
            preNode = curNode;
            curNode = nextNode;
        }

        return preNode;
    }
};

int main(int argc, char *argv[]) {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);

    ListNode *head = createListNode(arr, n);
    printListNode(head);

    ListNode *retNode = Solution().reverseKGroup(head, 2);
    printListNode(retNode);

    deleteListNode(retNode);
    return 0;
}