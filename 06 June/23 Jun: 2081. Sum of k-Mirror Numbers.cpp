

class Solution {
public:
    bool basekNumber(int k,long long i){
        string s = "";
        while(i>0){
            s+=to_string(i%k);
            i=i/k;
        }
        reverse(s.begin(),s.end());
      
        return isPalindrome(s);
    } 
    bool isPalindrome(string s){
        int n=s.length();
        int left=0;
        int right=n-1;

        while(left<right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    long long kMirror(int k, int n) {
        long long sum=0;
        long long len=1;
        while(n>0){
            int halfLen=(len+1)/2;
            int maxNum=0;
            int minNum=0;
            
            maxNum=pow(10,halfLen)-1;
            minNum=pow(10,halfLen-1);
            for(long long i=minNum;i<=maxNum;i++){
                string firstHalf=to_string(i);
                string secondHalf=to_string(i);
                reverse(secondHalf.begin(),secondHalf.end());
                string num="";
                if(len%2==0){
                    num=firstHalf+secondHalf;
                }
                else{
                    num=firstHalf.substr(0,halfLen-1)+secondHalf;
                }
                long long palNo = stoll(num);
                
                if(basekNumber(k,palNo)){
                    n--;
                    sum+=palNo;
                    if(n==0){
                        break;
                    }
                }
            }
            len++;
        }
        return sum;
    }
};
