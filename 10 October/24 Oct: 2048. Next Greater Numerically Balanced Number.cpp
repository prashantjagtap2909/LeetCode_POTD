class Solution {
public:
    int balance(int n){
        string s = to_string(n);
        int freq[10] = {0};
        for (char c : s) 
            freq[c - '0']++;

        for (char c : s) {
            int digit = c - '0';
            if (freq[digit] != digit)
                return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        n++;
        while (!balance(n)){
            n++;
        }
        return n;
    }
};
