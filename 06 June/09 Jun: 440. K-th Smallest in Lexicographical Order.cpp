class Solution {
public:
    int findKthNumber(int n, int k) {
        auto steps = [&](long long curr, long long nxt) {
            long long cnt = 0;
            while (curr <= n) {
                cnt += min((long long)n + 1, nxt) - curr;
                curr *= 10;
                nxt *= 10;
            }
            return cnt;
        };
        long long curr = 1;
        k--;
        while (k > 0) {
            long long cnt = steps(curr, curr + 1);
            if (cnt <= k) {
                curr++;
                k -= cnt;
            } else {
                curr *= 10;
                k--;
            }
        }
        return (int)curr;
    }
};
