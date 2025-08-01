class Solution {
private:
bool solver(int i,int j,string &s,string &p,vector<vector<int>>&dp)
{
    if(i<0 && j<0)
    {
        return true;
    }
    if(i<0 && j>=0)
    {
        return false;
    }
    if(i>=0 && j<0)
    {
        for(int ll=0;ll<=i;ll++)
        {
            if(p[ll]!='*'){return false;}
        }
        return true;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(p[i]==s[j] || p[i]=='?')
    {
        return dp[i][j]=solver(i-1,j-1,s,p,dp);
    }
    else
    {
        if(p[i]=='*')
        {
            return dp[i][j]=solver(i-1,j,s,p,dp)|solver(i,j-1,s,p,dp);
        }
        return dp[i][j]=false;
    }
}
public:
    bool isMatch(string s, string p) {
        int n=p.length();
        int m=s.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solver(n-1,m-1,s,p,dp);
    }
};
