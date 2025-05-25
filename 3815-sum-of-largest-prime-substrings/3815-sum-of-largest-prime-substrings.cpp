#define ll long long
class Solution {
    ll mulmod(ll a, ll b, ll mod) {
    ll result = 0;
    a %= mod;
    while (b) {
        if (b & 1)
            result = (__int128)result + a % mod;
        a = (__int128)a + a % mod;
        b >>= 1;
    }
    return result % mod;
}

// Modular exponentiation
ll power(ll a, ll b, ll mod) {
    ll result = 1;
    a %= mod;
    while (b) {
        if (b & 1)
            result = (__int128)result * a % mod;
        a = (__int128)a * a % mod;
        b >>= 1;
    }
    return result;
}

// Miller-Rabin test
bool millerTest(ll d, ll n, ll a) {
    ll x = power(a, d, n);
    if (x == 1 || x == n - 1)
        return true;
    while (d != n - 1) {
        x = (__int128)x * x % n;
        d <<= 1;
        if (x == 1) return false;
        if (x == n - 1) return true;
    }
    return false;
}

bool isPrime(ll n) {
    if (n < 2)
        return false;
    if (n < 4)
        return true;
    if (n % 2 == 0)
        return false;

    ll d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    // Known deterministic bases for long long (up to ~1e18)
    vector<ll> bases = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

    for (ll a : bases) {
        if (a >= n) break;
        if (!millerTest(d, n, a))
            return false;
    }
    return true;
}
public:
    long long sumOfLargestPrimes(string s) {
        ll n = s.length();
        ll ans = 0;
        map<ll , int>mp;
        priority_queue<ll>pq;
        for(int i = 0 ; i < n ; i++){
            string temp = "";
            for(int j = i ; j < n ; j++){
                temp += s[j];
                ll num = stoll(temp);
                if(isPrime(num) && mp.find(num) == mp.end()){
                    mp[num]++;
                    pq.push(num);
                }
            }
        }
        if(pq.size() == 0){
            return 0;
        }
        for(int i = 0 ; i < 3 ; i++){
            ans += pq.top();
            pq.pop();
            if(pq.empty()){
                break;
            }
        }
        return ans;
    }
};