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
    ListNode *deleteDuplicates(ListNode *head) {
//        // 递归方法
//        if (head == nullptr || head->next == nullptr) return head;
//
//        if (head->val == head->next->val) {
//            while (head != nullptr && head->next != nullptr && head->val == head->next->val) {
//                head = head->next;
//            }
//            return deleteDuplicates(head->next);
//        } else {
//            head->next = deleteDuplicates(head->next);
//            return head;
//        }

        // 双指针
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *dummyNode = new ListNode(-1);
        dummyNode->next = head;

        ListNode *preNode = dummyNode;
        ListNode *curNode = head;
        while (curNode != nullptr && curNode->next != nullptr) {
            if (curNode->next->val != preNode->next->val) {
                preNode = preNode->next;
                curNode = curNode->next;
            } else {
                while(curNode != nullptr && curNode->next != nullptr && preNode->next->val == curNode->next->val) {
                    curNode = curNode->next;
                }
                preNode->next = curNode->next;
                curNode = curNode->next;
            }
        }

        return dummyNode->next;
    }
};

int main(int argc, char *argv[]) {
    int arr[] = {1,2,3};
    int n = sizeof(arr) / sizeof(int);

    ListNode *head = createListNode(arr, n);
    printListNode(head);

    ListNode *retNode = Solution().deleteDuplicates(head);
    printListNode(retNode);

    deleteListNode(retNode);
    return 0;
}