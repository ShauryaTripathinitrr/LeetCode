class Solution {
/*private:
long long fact(int n,vector<int>&dp)
{
    if(n==0)
    {
        return 1;
    }
    if(dp[n]!=-1)return dp[n];

    return dp[n]=n*fact(n-1,dp)*1ll;
}
*/
public:
    int trailingZeroes(int n) {
        if(n==0)
        {
            return 0;
        }
        long long count=0;
        while(n/5>0)
        {
            count+=n/5;
            n=n/5;
        }
        return count;
    }
};