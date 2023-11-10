class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

         int n = nums.size();
        vector<int>ans(n, 0);
        int negativeId = 1;
        int positiveId = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] >= 0){
                ans[positiveId] = nums[i];
                positiveId += 2;
            }
            else{
                ans[negativeId] = nums[i];
                negativeId += 2;
            }
        }
        return ans;
    }
};
