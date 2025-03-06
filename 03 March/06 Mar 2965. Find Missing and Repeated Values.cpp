class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& arr) {
        int n  = arr.size();
        map<int,int> mp;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                mp[arr[i][j]]++;
            }
        }
        vector<int> ans(2,0);
        for(int i = 1;i<=n*n;i++){
            if(mp.find(i)==mp.end()){
                ans[1]  = i;
            }
            if(mp[i]==2){
                ans[0] = i;
            }
        }
        return ans;
    }
};
