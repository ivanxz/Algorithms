//
// Created by 谢卓 on 2021/3/23.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int p = 0, q = 0;
        int res = 1;
        for (int i = 1; i <= n; ++i) {
            p = q;
            q = res;
            res = p + q;
        }

        return res;
    }
//    // 数学方式求解
//    int climbStairs(int n) {
//        double sqrt5 = sqrt(5);
//        double fibn = pow((1 + sqrt5) / 2, n + 1) - pow((1 - sqrt5) / 2, n + 1);
//        return (int)round(fibn / sqrt5);
//    }
};

int main(int argc, char *argv[]) {
    cout << Solution().climbStairs(3) << endl;
    return 0;
}