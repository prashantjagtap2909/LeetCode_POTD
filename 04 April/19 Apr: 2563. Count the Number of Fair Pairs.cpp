class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        long long cnt=0;
        for(int l=0; l<n; l++){
            int x=nums[l], lo=lower-x, hi=upper-x;
            auto i = lower_bound(nums.begin()+l+1, nums.end(), lo);
            auto j = upper_bound(nums.begin()+l+1, nums.end(), hi);  
            cnt+=j-i;
        }
        return cnt; 
    }
};
