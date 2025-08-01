#define ll long long
class Solution {
    ll n , m;
    vector<vector<ll>>dp;
    ll solver(ll i , ll j , string &s , string &t){
        if(i < 0){
            return j + 1;
        }
        if(j < 0){
            return i + 1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i] == t[j]){
            return dp[i][j] = solver(i - 1 , j - 1 , s , t);
        }else{
            ll a = 1 + solver(i , j - 1 , s , t);//insert
            ll b = 1 + solver(i - 1 , j , s , t);//delete
            ll c = 1 + solver(i - 1 , j - 1 , s , t);//replace
            return dp[i][j] = min(a , min(b , c));
        }
    }
public:
    int minDistance(string word1, string word2) {
        n = word1.size();
        m = word2.size();
        dp.resize(n + 1 , vector<ll>(m + 1 , -1));
        return solver(n - 1 , m - 1 , word1 , word2);
    }
};