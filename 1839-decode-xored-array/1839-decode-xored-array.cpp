class Solution {
public:
    vector<int> decode(vector<int>& e, int first) {
        vector<int>ans(e.size()+1);
        ans[0]=first;
        for(int i=0;i<e.size();i++)
        {
           ans[i+1]=ans[i]^e[i];
        }
        return ans;
    }
};