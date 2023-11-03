class Solution {
int x = 0;
    void solve(int s,int k,int &ans,vector<int> &nums){
        if(s>=nums.size()){
            if(k==x)
                ans++;
            return;
        }
        solve(s+1,k|nums[s],ans,nums);
        solve(s+1,k,ans,nums);
    }
    public:
    int countMaxOrSubsets(vector<int>& nums) {
        int ans = 0;
        x = 0;
        for(auto &i: nums)x |= i;
        solve(0,0,ans,nums);
        return ans;
    }
};