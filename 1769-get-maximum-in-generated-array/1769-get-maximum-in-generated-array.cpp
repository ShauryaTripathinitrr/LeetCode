class Solution {
public:
    int getMaximumGenerated(int n)
    {
        if(n<2)return n;
        vector<int>v(n+1);
       v[0]=0;
       v[1]=1;
        for(int i=1;i<=n;i++)
        {
            if(!(i&1))
            {
                 v[i]=v[i/2];
            }
            else
            {
                v[i]=v[i/2]+v[i/2 +1];
            }
        }
        
        sort(v.begin(),v.end());
        return v[v.size()-1];
    }
};