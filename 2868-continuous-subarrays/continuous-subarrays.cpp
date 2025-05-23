#define ll long long
class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        ll n = nums.size();
        ll i = 0;
        ll j = 0;
        ll ans = 0;
        map<ll , ll>mp;
        while(j < n){
            mp[nums[j]]++;

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