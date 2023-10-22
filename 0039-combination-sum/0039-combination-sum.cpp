class Solution {
private:
void solve(int ind,vector<int>& candidates,int target,vector<vector<int>>&v,vector<int>ans,int n)
{
    if(ind == n){
        if(target == 0){
         v.push_back(ans);
    }
    return;
    }
    if(candidates[ind]<=target)
    {
        ans.push_back(candidates[ind]);
        solve(ind,candidates,target-candidates[ind],v,ans,n);
        ans.pop_back();
    }
    solve(ind+1,candidates,target,v,ans,n);
}
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>>v;
        vector<int>ans;

        solve(0,candidates,target,v,ans,candidates.size());

        return v;
    }
};