class Solution {
public:
    vector<int> findArray(vector<int>& p) {
        if(p.size()==1)
        return p;

        vector<int>ans(p.size());
        ans[0]=p[0];
        for(int i=1;i<p.size();i++)
        {
            ans[i]=p[i-1]^p[i];
        }
        return ans;
    }
};