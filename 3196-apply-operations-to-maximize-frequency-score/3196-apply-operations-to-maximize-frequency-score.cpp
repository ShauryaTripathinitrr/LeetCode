class Solution
{
public:
    long long sum(int i, int j, const vector<long long> &preSum)
    {
        if (i == 0)
            return preSum[j];
        return preSum[j] - preSum[i - 1];
    }

    long long get(int i, int j, int mid, const vector<int> &nums, const vector<long long> &preSum)
    {
        long long c1 = nums[mid] * 1LL * (mid - i + 1) - sum(i, mid, preSum);
        long long c2 = sum(mid, j, preSum) - (nums[mid] * 1LL * (j - mid + 1));
        return c1 + c2;
    }

    bool check(int mid, int n, long long k, const vector<int> &nums, const vector<long long> &preSum)
    {
        int i = 0, j = mid - 1;
        long long ans = 1e18;
        for (; j < n; j++, i++)
        {
            if ((j - i + 1) % 2 == 1)
            {
                long long c1 = get(i, j, (i + j) / 2, nums, preSum);
                ans = min(ans, c1);
            }
            else
            {
                long long c1 = get(i, j, (i + j) / 2, nums, preSum);
                long long c2 = get(i, j, (i + j) / 2 + 1, nums, preSum);
                ans = min({ans, c1, c2});
            }
        }
        return ans <= k;
    }

    int maxFrequencyScore(vector<int> &nums, long long k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> preSum(n, nums[0]);
        for (int i = 1; i < n; i++)
        {
            preSum[i] = preSum[i - 1] + nums[i];
        }
        int low = 1, high = n, ans = 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (check(mid, n, k, nums, preSum))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
    }
};