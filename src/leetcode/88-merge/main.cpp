//
// Created by 谢卓 on 2021/3/4.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j])
                nums1[k] = nums1[i--];
            else
                nums1[k] = nums2[j--];
        }
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums1 = {0};
    vector<int> nums2 = {1};
    Solution::merge(nums1, 0, nums2, 1);
    for (auto k: nums1) {
        cout << k << " ";
    }
    cout << endl;
    return 0;
}