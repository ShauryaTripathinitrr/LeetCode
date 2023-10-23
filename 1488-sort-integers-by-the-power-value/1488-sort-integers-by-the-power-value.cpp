class Solution {
public:
  int solve(int target,int& ans)
  {
     if(target==1)
     {
         return ans;
     }
     if(target%2==0)
     {
         ans=ans+1;
         return solve(target/2,ans);
     }
     else
     {
         ans=ans+1;
         return solve(target*3 +1,ans);
     }
  }
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>>v;
        int ans=0;

        for(int i=lo;i<=hi;i++)
        {
            int ans=0;
            int jam=solve(i,ans);
            v.push_back({jam,i});
        }
        sort(v.begin(),v.end());

        return v[k-1].second;
    }
};