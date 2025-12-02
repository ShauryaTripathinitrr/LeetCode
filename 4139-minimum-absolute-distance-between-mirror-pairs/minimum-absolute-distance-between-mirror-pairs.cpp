#define ll long long
class Solution {
public:
    ll get_rev(ll x){
        ll n = 0;
        while(x != 0){
            ll a = x % 10;
            n = (n * 10) + a;
            x /= 10;
        }
        return n;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        map<ll , int>mp;
        ll ans = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            if(mp.find(nums[i]) != mp.end()){
                ans = min((ll)ans ,(ll) i - mp[nums[i]]);
            }
            ll g = get_rev(nums[i]);
            mp[g] = i;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};