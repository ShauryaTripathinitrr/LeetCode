#define ll long long

class Solution {
public:
    ll power(int val, int po, int mod){
        ll ans = 1;
        
        while(po--){
            ans = (ans*val)%mod;
        }
        return ans;
    }
    
    ll helper(int i, int taken, int sum, int k, vector<int>& nums, int mod, vector<vector<vector<ll>>>& dp){
        int n = nums.size();
        
        if(i>=n){
            if(sum == k){
                return power(2, n-taken, mod)%mod;
            }
            
            return 0;
        }
        
        if(dp[i][taken][sum] != -1) return dp[i][taken][sum];
        
        ll notTake = helper(i+1, taken, sum, k, nums, mod, dp)%mod;
        ll take = 0;
        if((sum+nums[i])<=k) take = helper(i+1, taken+1, sum+nums[i], k, nums, mod, dp)%mod;
        
        return dp[i][taken][sum] = (notTake+take)%mod;
    }
    
    int sumOfPower(vector<int>& nums, int k) {
        int mod = 1e9+7;
        int n = nums.size();
        vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(k+1, -1)));
        return (int)helper(0, 0, 0, k, nums, mod, dp)%mod;
    }
};