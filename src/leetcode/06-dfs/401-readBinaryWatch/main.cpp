//
// Created by 谢卓 on 2021/3/19.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        dfs(num, 0, 0, 0);
        return res;
    }

private:
    vector<string> res;
    const int hourLed[10]{1, 2, 4, 8, 0, 0, 0, 0, 0, 0};
    const int minuteLed[10]{0, 0, 0, 0, 1, 2, 4, 8, 16, 32};

    void dfs(int num, int index, int hour, int minute) {
        if (hour > 11 || minute > 59) return;
        if (num == 0) {
            string time = to_string(hour) + ":" + (minute < 10 ? "0" + to_string(minute) : to_string(minute));
            res.push_back(time);
            return;
        }

        for (int i = index; i < 10; ++i) {
            dfs(num - 1, i + 1, hour + hourLed[i], minute + minuteLed[i]);
        }
    }
};

int main(int argc, char *argv[]) {
    vector<string> res = Solution().readBinaryWatch(1);
    for (auto &str : res) {
        cout << str << " ";
    }
    cout << endl;
    return 0;
}