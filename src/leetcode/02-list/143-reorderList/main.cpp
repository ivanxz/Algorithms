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
    void reorderList(ListNode *head) {
//        // 节点存储
//        vector<ListNode *> vec;
//        ListNode *node = head;
//        while (node != nullptr) {
//            vec.emplace_back(node);
//            node = node->next;
//        }
//
//        int i = 0, j = (int) vec.size() - 1;
//        while (i < j) {
//            vec[i]->next = vec[j];
//            i++;
//
//            if (i == j)
//                break;
//
//            vec[j]->next = vec[i];
//            j--;
//        }
//
//        vec[i]->next = nullptr;


        if (head == nullptr) return;

        ListNode *midNode = middleNode(head);
        ListNode *l1 = head;
        ListNode *l2 = midNode->next;
        midNode->next = nullptr;
        l2 = reverseList(l2);
        mergeList(l1, l2);
    }

private:
    ListNode *middleNode(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode *reverseList(ListNode *head) {
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

    void mergeList(ListNode *l1, ListNode *l2) {
        ListNode *nex1, *next2;
        while (l1 != nullptr && l2 != nullptr) {
            nex1 = l1->next;
            next2 = l2->next;

            l1->next = l2;
            l1 = nex1;

            l2->next = l1;
            l2 = next2;
        }
    }
};

int main(int argc, char *argv[]) {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(int);

    ListNode *head = createListNode(arr, n);
    printListNode(head);

    Solution().reorderList(head);
    printListNode(head);

    deleteListNode(head);
    return 0;
}