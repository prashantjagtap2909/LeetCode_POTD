class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if(n&1){
            return 0;
        }
        int balanced = 0;
        for(int i = 0; i<n; i++){
            if(s[i] == '(' || locked[i] == '0'){
                balanced++;
            }
            else{
                balanced--;
            }
            if(balanced < 0) return 0;
        }
        balanced = 0;
        for(int i = n-1; i>=0; i--){
            if(s[i] == ')' || locked[i] == '0'){
                balanced++;
            }else{
                balanced--;
            }
            if(balanced < 0) return 0;
        }
         return 1;
    }
};
