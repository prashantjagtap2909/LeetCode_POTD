class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size(), current_count =1, result = 0;
        for(int i=0;i<n+k-2;++i){

            if(colors[i%n]!=colors[(i+1)%n]){
                current_count++;
            }else{
                current_count =1;
            }
            result += (current_count>=k);
        }
        return result;
    }
};
