#define ll long long
class Solution {
    private:
    vector<vector<ll>>dp;
    bool solver(ll index , vector<int>& nums , ll t){
        if(t == 0){
            return true;
        }
        if(index >= nums.size()){
            return false;
        }
        if(dp[index][t] != -1){
            return dp[index][t];
        }
        bool pick = false;
        bool npick = false;

        if(nums[index] <= t){
            pick |= solver(index + 1 , nums , t - nums[index]);
        }
        npick |= solver(index + 1 , nums , t);

        return dp[index][t] = pick | npick;
    }
public:
    bool canPartition(vector<int>& nums) {
        ll n = nums.size();
        ll a = accumulate(nums.begin() , nums.end() , 0ll);

        if(a & 1){
            return false;
        }
        ll t = a / 2;
        dp.resize(n , vector<ll>(t + 1 , -1));
        return solver(0 , nums , t);
    }
};