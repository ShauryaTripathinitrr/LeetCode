class Solution {
public:
    int minimumLength(string s) 
    {
        map<char,int>mp;
        for(auto it:s)
        {
            mp[it]++;
        }
        int cnt=0;
        
        for(auto it:mp)
        {
            if(it.second&1 && it.second>=1)
            {
                cnt++;
            }
            else if(it.second%2==0 && it.second>=2)
            {
                cnt+=2;
            }
        }
        return cnt;
    }
};