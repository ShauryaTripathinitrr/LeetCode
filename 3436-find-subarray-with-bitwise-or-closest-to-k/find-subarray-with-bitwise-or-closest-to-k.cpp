#define ll long long
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        ll ans = INT_MAX;
        ll i = 0;
        ll j = 0;
        ll jam = 0;

        vector<int>contri(32 , 0);
        ll n = nums.size();
        if(n == 1){
            return abs(nums[0] - k);
        }
        while(j < n){
            jam |= nums[j];
            int it = nums[j];
             for(int i = 30 ; i>=0 ; i--){
                int bit = (it >> i) & 1;
                contri[i] += bit;
            }
            if(jam > 0)
            ans = min(ans , abs(k - jam));
            while(i < n && jam > k){
                int nu = nums[i];

                for(int l = 30 ; l >= 0 ; l--){
                    if(contri[l] == 0){
                        continue;
                    }
                    int bit = (nu >> l) & 1ll;
                    contri[l] -= bit;
                    if(contri[l] == 0){
                        jam = jam ^ (1ll << l);
                    }
                }
                if(jam > 0)
                ans = min(ans , abs(jam - k));

                i++;
            } 
            if(jam > 0)
            ans = min(ans , abs(jam - k));

            j++;
        }
        if(jam > 0)
        ans = min(ans , abs(jam - k));
        
        return ans;
    }
};