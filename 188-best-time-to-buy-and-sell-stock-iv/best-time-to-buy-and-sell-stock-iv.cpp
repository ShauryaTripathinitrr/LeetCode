#define ll long long
class Solution {
    ll n;
    vector<vector<vector<ll>>>dp;
    ll solver(ll index , ll buy , ll k , vector<int>& prices){
        if(k == 0){
            return 0;
        }
        if(index >= n){
            return 0;
        }
        if(dp[index][buy][k] != -1){
            return dp[index][buy][k];
        }
        ll profit = 0;
        if(k > 0){
            if(buy){
                profit = max(-1 * prices[index] + solver(index + 1 , 0 , k , prices) , solver(index + 1 , 1 , k , prices)); 
            }else{
                profit = max(prices[index] + solver(index + 1 , 1 , k - 1 , prices) , solver(index + 1 , 0 , k , prices));
            }
        }
        return dp[index][buy][k] = profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        dp.resize(n , vector<vector<ll>>(2 , vector<ll>(k + 1 , -1)));
        return solver(0 , 1 , k , prices);
    }
};