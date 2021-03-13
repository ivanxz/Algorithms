//
// Created by 谢卓 on 2021/3/7.
//

#include <iostream>
#include <vector>
#include <list>

using namespace std;

class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() : data(base) {

    }

    void add(int key) {
        int t = hash(key);
        for (auto it = data[t].begin(); it != data[t].end(); it++) {
            if ((*it) == key) {
                return;
            }
        }
        data[t].push_back(key);
    }

    void remove(int key) {
        int t = hash(key);
        for (auto it = data[t].begin(); it != data[t].end(); it++) {
            if ((*it) == key) {
                data[t].erase(it);
                return;
            }
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int t = hash(key);
        for (auto it = data[t].begin(); it != data[t].end(); it++) {
            if ((*it) == key) {
                return true;
            }
        }
        return false;
    }

private:
    vector<list<int>> data;
    static const int base = 769;  // 取质数
    static int hash(int key) {  // hash函数
        return key % base;
    }
};

int main(int argc, char *argv[]) {
    cout << endl;
    return 0;
}