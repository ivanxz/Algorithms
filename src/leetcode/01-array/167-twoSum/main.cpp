//
// Created by 谢卓 on 2021/3/4.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static vector<int> twoSum(vector<int> &numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while (l < r) {
            if (numbers[l] + numbers[r] == target)
                break;
            else if (numbers[l] + numbers[r] > target)
                r--;
            else
                l++;
        }

        return {l + 1, r + 1};
    }
};

int main(int argc, char *argv[]) {
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    vector<int> ret = Solution::twoSum(numbers, target);
    for (auto n: ret) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}