class Solution {
public:
    const int MOD = 1e9 + 7;

    int ans(int n, int x, int i, vector<vector<int>> &dp) {
        if (n == 0) return 1; 
        if (n < 0) return 0;
        if (i > n) return 0; // Prevent out-of-bounds

        if (dp[n][i] != -1) return dp[n][i];

         long long power = pow(i , x);

        long long taken = 0;
        if (n >= power) {
            taken = ans(n - power, x, i + 1, dp) % MOD;
        }

        long long not_taken = ans(n, x, i + 1, dp) % MOD;

        return dp[n][i] = (taken + not_taken) % MOD;
    }

    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return ans(n, x, 1, dp);
    }
};
