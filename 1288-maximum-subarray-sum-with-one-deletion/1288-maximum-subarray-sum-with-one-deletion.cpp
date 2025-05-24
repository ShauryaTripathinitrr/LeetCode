class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> forward(n), backward(n);

        forward[0] = arr[0];
        backward[n - 1] = arr[n - 1];

        for (int i = 1; i < n; i++) {
            forward[i] = max(forward[i - 1] + arr[i], arr[i]);
        }

        for (int i = n - 2; i >= 0; i--) {
            backward[i] = max(backward[i + 1] + arr[i], arr[i]);
        }

        int ans = *max_element(forward.begin(), forward.end());

        for (int i = 1; i < n - 1; i++) {
            ans = max(ans, forward[i - 1] + backward[i + 1]);
        }

        return ans;
    }
};
