//
// Created by 谢卓 on 2021/3/4.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int maxArea(vector<int> &height) {
        int l = 0, r = height.size() - 1;
        int ans = 0, area;
        while (l < r) {
            area = min(height[l], height[r]) * (r - l);
            ans = max(ans, area);

            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    vector<int> height = {4, 3, 2, 1, 4};
    cout << Solution::maxArea(height) << endl;
    return 0;
}