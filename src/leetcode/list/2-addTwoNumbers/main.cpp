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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = nullptr, *tail = nullptr;

        int m, n, sum, carry = 0;
        while (l1 != nullptr || l2 != nullptr) {
            m = l1 ? l1->val : 0;
            n = l2 ? l2->val : 0;

            sum = m + n + carry;
            if (head == nullptr) {
                head = tail = new ListNode(sum % 10);
            } else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }

            carry = sum / 10;

            if (l1 != nullptr)
                l1 = l1->next;

            if (l2 != nullptr)
                l2 = l2->next;
        }

        if (carry > 0) {
            tail->next = new ListNode(carry);
        }

        return head;
    }
};

int main(int argc, char *argv[]) {
    int l1[] = {2, 4, 3};
    int l2[] = {5, 6, 4};

    ListNode *head1 = createListNode(l1, 3);
    printListNode(head1);
    ListNode *head2 = createListNode(l2, 3);
    printListNode(head2);

    ListNode *retNode = Solution().addTwoNumbers(head1, head2);
    printListNode(retNode);

    deleteListNode(retNode);
    return 0;
}