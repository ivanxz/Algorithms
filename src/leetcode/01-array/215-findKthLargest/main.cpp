//
// Created by 谢卓 on 2021/3/4.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(nullptr));
        auto n = nums.size();
        return quickSelect(nums, 0, n - 1, n - k);
    }

private:
    inline int partition(vector<int>& a, int l, int r) {
        int x = a[r], i = l - 1;
        for (int j = l; j < r; ++j) {
            if (a[j] <= x) {
                swap(a[++i], a[j]);
            }
        }
        swap(a[i + 1], a[r]);
        return i + 1;
    }

    inline int randomPartition(vector<int>& a, int l, int r) {
        int i = rand() % (r - l + 1) + l;
        swap(a[i], a[r]);
        return partition(a, l, r);
    }

    inline int quickSelect(vector<int>& a, int l, int r, int index) {
        int q = randomPartition(a, l, r);
        if (q == index)
            return a[q];
        else
            return q < index ? quickSelect(a, q + 1, r, index) : quickSelect(a, l, q - 1, index);
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int k = 4;
    Solution solution;
    cout << solution.findKthLargest(nums, k) << endl;
    return 0;
}