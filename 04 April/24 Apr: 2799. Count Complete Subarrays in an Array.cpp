class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int k = unordered_set<int>(nums.begin(),nums.end()).size();
        int res = 0, left = 0;
        unordered_map<int, int> mpp;

        for (int i = 0; i < nums.size(); ++i) {
            mpp[nums[i]]++;
            while (mpp.size() == k) {
                res += nums.size() - i;  
                mpp[nums[left]]--;
                if (mpp[nums[left]] == 0) mpp.erase(nums[left]);
                left++;
            }
        }
        return res;
    }
};
