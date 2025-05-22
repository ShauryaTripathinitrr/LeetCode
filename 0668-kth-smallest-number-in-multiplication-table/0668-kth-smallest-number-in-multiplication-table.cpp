#define ll long long
class Solution {
    private:
    bool check(ll num , ll m , ll n , ll k){
        ll sum = 0;

        for(ll i = 1 ; i <= m ; i++){
            sum += min(n , num / i);
        }

        return sum < k;
    }
public:
    int findKthNumber(int m, int n, int k) {
        ll low = 1;
        ll high = m * n;

        while(low <= high){
            ll mid = low + (high - low)/2;

            if(check(mid , m , n , k)){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return low;
    }
};