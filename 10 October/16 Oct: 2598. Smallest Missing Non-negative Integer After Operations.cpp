class Solution {
    int mod[100000]={0};
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n=nums.size();
        memset(mod, 0, value*4);
        for(int x:nums){
            x%=value;
            if (x<0) x+=value;
            mod[x]++;
        }
        for(int i=0; i<n; i++)
            if(--mod[i%value]<0) return i;
        return n;
    }
};
