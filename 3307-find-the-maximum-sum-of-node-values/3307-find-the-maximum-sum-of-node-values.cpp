class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<int> diff(n, 0);
        long long sum = 0l;
        for(int i=0;i<n;i++) {
            diff[i] = (nums[i]^k )- nums[i];
            sum+=nums[i]*1l;
        } 
        sort(diff.begin(), diff.end(), greater<int>());
        for(int i=0;i<n-1;i+=2) {
            if((diff[i] + diff[i+1])>0) {
                sum+=(diff[i] + diff[i+1])*1l;
            }
        }
        return sum;
    }
};