#define ll long long
class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        ll n = nums.size();

        ll sum = 0;
        sort(nums.begin() , nums.end());
        int a = 0 , b = n - 2 , c = n - 1;

        while(a < b){
            //cout << a << " " << b << " " << c << endl;
            sum += nums[b];
            c -= 2;
            b -= 2;
            a++;
        }
        return sum;
        
    }
};