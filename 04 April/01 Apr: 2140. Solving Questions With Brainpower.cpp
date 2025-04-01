class Solution {
public:
    vector<long long>dp;
    long long fn(vector<vector<int>>& nums,int idx){
        if(idx>=nums.size())return 0;
        if(dp[idx]!=-1)return dp[idx];

        long long pick=nums[idx][0]+fn(nums,idx+nums[idx][1]+1);
        long long nonpick=fn(nums,idx+1);

        return dp[idx]= max(pick,nonpick);
    }

    long long mostPoints(vector<vector<int>>& nums) {
        dp.resize(nums.size(),-1);
        return fn(nums,0);
    }
};
