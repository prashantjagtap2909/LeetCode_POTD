class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long sum=0, des=0;
        int prev=-1;
        for (int x : prices){
            const bool isMinus1=x+1==prev; 
            sum+=(-(!isMinus1) & des*(des+1)/2);
            des=(-isMinus1 & des)+1;
            prev=x;
        }
        sum+=des*(des+1)/2;
        return sum;
    }
};
