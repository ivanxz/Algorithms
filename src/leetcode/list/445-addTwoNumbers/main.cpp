//
// Created by 谢卓 on 2021/3/7.
//

#include <iostream>
#include <vector>
#include <stack>

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
        stack<int> s1, s2;
        while (l1 != nullptr) {
            s1.push(l1->val);
            l1 = l1->next;
        }

        while (l2 != nullptr) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        int m, n, sum, carry = 0;
        ListNode *head = nullptr;
        while (!s1.empty() || !s2.empty() || carry != 0) {
            m = s1.empty() ? 0 : s1.top();
            n = s2.empty() ? 0 : s2.top();

            if (!s1.empty())
                s1.pop();

            if (!s2.empty())
                s2.pop();

            sum = m + n + carry;
            carry = sum / 10;
            ListNode *tail = new ListNode(sum % 10);
            tail->next = head;
            head = tail;
        }

        return head;
    }
};

int main(int argc, char *argv[]) {
    int l1[] = {7, 2, 4, 3};
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