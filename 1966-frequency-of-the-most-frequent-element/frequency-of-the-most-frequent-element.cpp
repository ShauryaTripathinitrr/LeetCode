class Solution {
private:
    bool check(long long mid, long long k, vector<int>& nums) {
        long long sum = 0; // Sum of the current window
        long long n = nums.size();
        
        for (long long i = 0; i < mid; ++i) {
            sum += nums[i];
        }
        
        // Check the first window
        long long cost = (nums[mid - 1] * mid) - sum;
        if (cost <= k) {
            return true;
        }
        
        // Sliding window
        for (long long i = mid; i < n; ++i) {
            sum += nums[i] - nums[i - mid];
            cost = (nums[i] * mid) - sum;
            if (cost <= k) {
                return true;
            }
        }
        
        return false;
    }

public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); // Sort the array
        long long low = 1, high = nums.size();
        int result = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (check(mid, k, nums)) {
                result = mid; // Update result
                low = mid + 1; // Try for a larger frequency
            } else {
                high = mid - 1; // Try for a smaller frequency
            }
        }

        return result;
    }
};
