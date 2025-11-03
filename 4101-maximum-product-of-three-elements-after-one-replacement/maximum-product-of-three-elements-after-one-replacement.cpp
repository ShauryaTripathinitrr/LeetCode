#define ll long long
class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        for(auto & x : nums){
            if( x < 0){
                x = -1 * x;
            }
        }
        sort(nums.begin() , nums.end());

        ll ans = nums.back()*1ll * nums[nums.size() - 2]*1ll * 1e5;

        return ans;
    }
};