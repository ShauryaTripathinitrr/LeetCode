class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        vector<pair<int, int>> surplus_units;
        vector<pair<int, int>> zeros;

        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] > 1) {
                    int extra = grid[i][j] - 1;
                    while (extra--) {
                        surplus_units.push_back({i, j});
                    }
                } else if (grid[i][j] == 0) {
                    zeros.push_back({i, j});
                }
            }
        }

        int k = zeros.size();
        int ans = INT_MAX;
        sort(surplus_units.begin(), surplus_units.end());
        do {
            int total = 0;
            for (int i = 0; i < k; ++i) {
                total += abs(zeros[i].first - surplus_units[i].first) +
                         abs(zeros[i].second - surplus_units[i].second);
            }
            ans = min(ans, total);
        } while (next_permutation(surplus_units.begin(), surplus_units.end()));

        return ans;
    }
};
