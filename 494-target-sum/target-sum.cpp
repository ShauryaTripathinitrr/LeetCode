#define ll long long
class Solution {
    ll n;
    vector<vector<ll>>dp;
    ll solver(ll index , ll t , vector<int>& nums){
        if(index >= nums.size()){
            if(t == 0){
            return 1;
        }
            return 0;
        }
        if(dp[index][t] != -1){
            return dp[index][t];
        }
        ll pick = 0;
        ll npick = 0;

        if(t - nums[index] >= 0){
            pick += solver(index + 1 , t - nums[index] , nums);
        }
        npick += solver(index + 1 , t , nums);

        return dp[index][t] = pick + npick;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        ll acc = accumulate(nums.begin() , nums.end() , 0ll);
        if((acc - target) % 2 == 0 && (acc >= target)){
            ll t = (acc - target) >> 1;
            dp.resize(n + 1 , vector<ll>(t + 1 , -1));
            return solver(0 , t , nums);
        }
        return 0;
    }
};