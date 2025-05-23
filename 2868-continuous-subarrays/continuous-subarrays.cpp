#define ll long long
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        ll n = nums.size();

        vector<ll>diff;

        for(int i = 1 ; i < n ; i++){
            diff.push_back(nums[i] - nums[i - 1]);
        }

        ll i = 0;
        ll j = 0;
        ll k = n;
        ll sum = 0;
        ll ans = 0;
        map<ll , ll>mp;
        while(j < k){
            mp[nums[j]]++;

            auto f = mp.begin();
            ll a = f -> first;
            auto l = prev(mp.end());
            ll b = l -> first;

            while(i < n && abs((prev(mp.end()) -> first) - ((mp.begin() -> first))) > 2){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                i++;
            }

            ans += (j - i + 1);
            j++;
        }
        return ans;
    }
};