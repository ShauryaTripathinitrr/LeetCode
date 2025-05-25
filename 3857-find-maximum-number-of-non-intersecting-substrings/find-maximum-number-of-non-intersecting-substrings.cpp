class Solution {
    private:
    vector<int>dp;
    int fun(int t , vector<pair<int , int>> &v){
        int low = 1;
        int high = v.size() - 1;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(v[mid].first > t){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
    int solver(int index , vector<pair<int , int>> &v){
        if(index >= v.size()){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        int pick = 0;
        int notpick = solver(index + 1 , v);

        int ind = fun(v[index].second , v);

        pick = 1 + solver(ind , v);

        return dp[index] = max(pick , notpick);
    }
public:
    int maxSubstrings(string word) {
        vector<vector<int>>freq(26);

        for(int i = 0 ; i < word.length() ; i++){
            freq[word[i] - 'a'].push_back(i);
        }
        vector<pair<int , int>>v;


        for(int i = 0 ; i < 26 ; i++){
            if(freq[i].size() > 1){
                int j = 0;
                for(int k = 1 ; k < freq[i].size() ; k++){
                    if( (freq[i][k] - freq[i][j] + 1) >= 4){
                        while(j < k && (freq[i][k] - freq[i][j] + 1) >= 4){
                            v.push_back({freq[i][j] , freq[i][k]});
                            j++;
                        }
                    }
                }
            }
        }
        dp.resize(v.size() + 1 , -1);
        sort(v.begin() , v.end());
        return solver(0 , v);
    }
};