//
// Created by 谢卓 on 2021/3/19.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<string>> res;
    vector<bool> cols;
    vector<bool> dia1;
    vector<bool> dia2;

    void dfs(int n, int index, vector<int> &row) {
        if (n == row.size()) {
            res.emplace_back(genBoard(n, row));
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (!cols[i] && !dia1[index + i] && !dia2[index - i + n - 1]) {
                row.push_back(i);
                cols[i] = true;
                dia1[index + i] = true;
                dia2[index - i + n - 1] = true;
                dfs(n, index + 1, row);
                cols[i] = false;
                dia1[index + i] = false;
                dia2[index - i + n - 1] = false;
                row.pop_back();
            }
        }
    }

    vector<string> genBoard(int n, vector<int> &row) {
        vector<string> board(n, string(n, '.'));
        for (int i = 0; i < n; ++i) {
            board[i][row[i]] = 'Q';
        }

        return board;
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        cols = vector<bool>(n, false);
        dia1 = vector<bool>(2 * n - 1, false);
        dia2 = vector<bool>(2 * n - 1, false);

        vector<int> row;
        dfs(n, 0, row);
        return res;
    }
};

int main(int argc, char *argv[]) {
    vector<vector<string>> res = Solution().solveNQueens(8);
    for (auto &vec : res) {
        for (const auto &str : vec) {
            cout << str << endl;
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}