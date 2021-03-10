//
// Created by 谢卓 on 2021/3/3.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> record;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = record.find(target - nums[i]);
            if (it != record.end()) {
                return {it->second, i};
            } else {
                record[nums[i]] = i;
            }
        }

        return {};
    }
};

int main(int argc, char *argv[]) {
    vector<int> nums = {3, 2, 3};
    int target = 6;
    vector<int> ret = Solution().twoSum(nums, target);
    for (auto k : ret) {
        cout << k << " ";
    }
    cout << endl;
    return 0;
}