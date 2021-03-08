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
    ListNode *insertionSortList(ListNode *head) {
        if (head == nullptr) return head;

        ListNode *dummyNode = new ListNode(-1);
        dummyNode->next = head;

        ListNode *tailNode = head;          // tailNode指向已排好序部分的尾结点
        ListNode *curNode = head->next;     // curNode是下一个待排序的结点
        while (curNode != nullptr) {
            if (curNode->val < tailNode->val) {
                ListNode *posNode = dummyNode; // 定义一个pos指针，用于每次从头（dummy处）寻找该插入cur的结点的位置。比如1->3，cur是2，那pos就在1处。
                while (posNode->next->val <
                       curNode->val) { posNode = posNode->next; } // 将pos定位到已排好序的且比cur小的部分中的最大的那个结点。posNode= -1 -> 4 -> 2 -> 1 -> 3 -> NULL
                tailNode->next = curNode->next; // 断链。比如dummy->4->2->1->3，tail是4，cur是2，则让4->1，把2拎出来。tailNode= 4 -> 1 -> 3 -> NULL
                curNode->next = posNode->next;  // pos此时在dummy处（因为4大于2），则让 2->4。curNode= 2 -> 4 -> 1 -> 3 -> NULL
                posNode->next = curNode;    // 上一步相当于断掉了dummy->4，现在重新接起来。posNode= -1 -> 2 -> 4 -> 1 -> 3 -> NULL

                curNode = tailNode->next;   // 让cur重新回到下一个待排序的结点处
            } else {
                tailNode = tailNode->next;
                curNode = curNode->next;
            }
        }

        return dummyNode->next;
    }
};

int main(int argc, char *argv[]) {
    int arr[] = {4, 2, 1, 3};
    int n = sizeof(arr) / sizeof(int);

    ListNode *head = createListNode(arr, n);
    printListNode(head);

    ListNode *retNode = Solution().insertionSortList(head);
    printListNode(retNode);

    deleteListNode(retNode);
    return 0;
}