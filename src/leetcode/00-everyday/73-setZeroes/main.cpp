//
// Created by 谢卓 on 2021/3/21.
//

#include <iostream>
#include <queue>
#include <sstream>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool flag = false;
        for (int i = 0; i < m; ++i) {
            if (0 == matrix[i][0])
                flag = true;
            for (int j = 1; j < n; ++j) {
                if (0 == matrix[i][j])
                    matrix[i][0] = matrix[0][j] = 0;
            }
        }

        cout << flag << endl;
        for (auto &vec: matrix) {
            for (auto k : vec) {
                cout << k << " ";
            }
            cout << endl;
        }

        for (int i = m - 1; i >= 0; --i) {
            for (int j = 1; j < n; ++j) {
                if (0 == matrix[i][0] || 0 == matrix[0][j])
                    matrix[i][j] = 0;
            }
            if (flag)
                matrix[i][0] = 0;
        }
    }
};

int main(int argc, char *argv[]) {
    vector<vector<int>> matrix{{1,  2,  3,  4},
                               {5,  0,  7,  8},
                               {0,  10, 11, 12},
                               {13, 14, 15, 0}};
    Solution().setZeroes(matrix);
    for (auto &vec: matrix) {
        for (auto k : vec) {
            cout << k << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}