//
// Created by 谢卓 on 2021/3/13.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfMatches(int n) {
        return matches(n);
    }

private:
    int matches(int n) {
        if (1 == n) {
            return 0;
        }

        if (1 == n % 2) {
            return (n - 1) / 2 + matches((n - 1) / 2 + 1);
        }

        return n / 2 + matches(n / 2);
    }
};

int main(int argc, char *argv[]) {
    cout << Solution().numberOfMatches(7) << endl;
    return 0;
}