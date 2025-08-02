#define ll long long
class Solution {
    ll n;
    vector<vector<vector<ll>>>dp;
    ll solver(ll index , ll buy , ll cnt , vector<int>& prices){
        if(index >= n){
            return 0;
        }
        if(dp[index][buy][cnt] != -1){
            return dp[index][buy][cnt];
        }
        ll profit = 0;
        if(cnt < 2){
            if(buy){
                profit = max(-1 * prices[index] + solver(index + 1 , 0 , cnt , prices) , solver(index + 1 , 1 , cnt , prices));
            }else{
                profit = max(prices[index] + solver(index + 1 , 1 , cnt + 1 , prices) , solver(index + 1 , 0 , cnt , prices));
            }
        }
        return dp[index][buy][cnt] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
         n = prices.size();
         dp.resize(n , vector<vector<ll>>(2 , vector<ll>(3 , -1)));
        return solver(0 , 1 , 0 , prices);
    }
};