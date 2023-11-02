class Solution {
public:
    int numberOfSteps(int n) {
        
        long long count=0;
        while(n!=0)
        {
            if(!(n&1))
            {
                n=n>>1;
                count++;
            }
            else
            {
                count++;
                n=n-1;
            }
        }
        return count;
    }
};