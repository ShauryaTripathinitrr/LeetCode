#define ll long long
class Solution {
    ll n;
    vector<vector<ll>>dp;
    ll solver(ll index , ll buy , vector<int>& prices){
        if(index >= n){
            return 0;
        }
        if(dp[index][buy] != -1){
            return dp[index][buy];
        }
        ll profit = 0;
        if(buy){
            profit = max(-1 * prices[index] + solver(index + 1 , 0 , prices) , solver(index + 1 , 1 , prices));
        }else{
            profit = max(prices[index] + solver(index + 1 , 1 , prices) , solver(index + 1 , 0 , prices));
        }   
        return dp[index][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp.resize(n + 1 , vector<ll>(2 , -1));
        return solver(0 , 1 , prices);
    }
};