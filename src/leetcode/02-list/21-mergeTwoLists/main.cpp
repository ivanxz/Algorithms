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
        ListNode *delNode = curNode;
        curNode = curNode->next;
        delete delNode;
    }
}

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *dummyNode = new ListNode(-1);

        ListNode *curNode = dummyNode;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                curNode->next = l1;
                l1 = l1->next;
            } else {
                curNode->next = l2;
                l2 = l2->next;
            }

            curNode = curNode->next;
        }

        curNode->next = l1 == nullptr ? l2 : l1;
        return dummyNode->next;
    }
};

int main(int argc, char *argv[]) {
    int l1[] = {1, 2, 4};
    int l2[] = {1, 3, 4};

    ListNode *head1 = createListNode(l1, 3);
    printListNode(head1);
    ListNode *head2 = createListNode(l2, 3);
    printListNode(head2);

    ListNode *retNode = Solution().mergeTwoLists(head1, head2);
    printListNode(retNode);

    deleteListNode(retNode);
    return 0;
}