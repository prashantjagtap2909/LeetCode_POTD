class Solution {
public:
    int numberOfWays(string corridor) 
    {
        int s = count(corridor.begin(),corridor.end(),'S');
        if(s&1 || s==0)
            return 0;
        int seats = 0,plants=0;
        long long ans = 1;
        for(char c : corridor)
        {
            if(c=='S')
            {
                if(seats!=2)
                    seats++;
                else
                {
                    ans = (ans*(plants+1))%1000000007;
                    seats = 1;
                    plants = 0;
                }
            }
            else
            {
                if(seats==2)
                    plants++;
            }
        }
        return ans;
    }
};
