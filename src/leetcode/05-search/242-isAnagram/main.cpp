//
// Created by 谢卓 on 2021/3/3.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
//        unordered_map<char, int> record;
//        for (auto c: s) {
//            record[c]++;
//        }
//
//        for (auto c: t) {
//            if (record.count(c)) {
//                record[c]--;
//                if (0 == record[c]) record.erase(c);
//            } else {
//                return false;
//            }
//        }
//
//        return record.empty();

        if (s.length() != t.length())
            return false;

        int freq[26] = {};
        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++)
            if (freq[i] != 0)
                return false;

        return true;
    }
};

int main(int argc, char *argv[]) {
    cout << Solution().isAnagram("anagram", "nagaram") << endl;
    return 0;
}