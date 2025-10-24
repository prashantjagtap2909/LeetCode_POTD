class Solution {
public:
    bool balanced(int n) {
        string s = to_string(n);
        unordered_map<char, int> count;
        for (char c : s) count[c]++;
        for (auto &p : count) {
            if (p.second != (p.first - '0')) return false;
        }
        return true;
    }

    int nextBeautifulNumber(int n) {
        int m = n + 1;
        while (m < 62466666) {
            if (balanced(m)) return m;
            m++;
        }
        return 0;
    }
};
