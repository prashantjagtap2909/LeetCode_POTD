class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // dp[z][o] = maximum number of strings with at most z zeros and o ones
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (auto &s : strs) {
            int zeros = 0, ones = 0;
            for (char c : s) {
                if (c == '0') zeros++;
                else ones++;
            }

            // Important: iterate backwards (0/1 knapsack)
            for (int z = m; z >= zeros; z--) {
                for (int o = n; o >= ones; o--) {
                    dp[z][o] = max(dp[z][o], dp[z - zeros][o - ones] + 1);
                }
            }
        }

        return dp[m][n];
    }
};
