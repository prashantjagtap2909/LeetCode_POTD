class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n=nums.size();
        long long dp0=0, dp1=INT_MIN;
        for(int i=1; i<=n; i++){
            const long long x=nums[i-1], xk=x^k;
            const long long dp_0=max(x+dp0, xk+dp1);
            dp1=max(x+dp1, xk+dp0);
            dp0=dp_0;
        }
        return dp0;
    }
};
