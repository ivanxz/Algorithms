//
// Created by 谢卓 on 2021/3/3.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
//    unordered_set<int> history;
//
//    bool isHappy(int n) {
//        if (n == 1)
//            return true;
//        if (history.count(n))
//            return false;
//
//        history.insert(n);
//        int tmp = 0;
//        while (n != 0) {
//            tmp += (n % 10) * (n % 10);
//            n /= 10;
//        }
//
//        return isHappy(tmp);
//    }

    bool isHappy(int n) {
        unordered_set<int> record;
        while (n != 1 && !record.count(n)) {
            record.insert(n);
            n = getNext(n);
        }

        return n == 1;
    }

    int getNext(int n) {
        int sum = 0;
        while (n != 0) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }

        return sum;
    }
};

int main(int argc, char *argv[]) {
    cout << Solution().isHappy(19) << endl;
    return 0;
}