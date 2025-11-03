class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        sort(nums.begin() , nums.end());

        ans.push_back(-1);
        for(int i = 1 ; i < n ; i++){
            if(nums[i] - nums[i - 1] != 1){
                int k = 1;
                while(ans.back() != nums[i] - 1){
                    ans.push_back(nums[i - 1] + k);
                    k++;
                }
            }
        }
        reverse(ans.begin() , ans.end());
        ans.pop_back();
        reverse(ans.begin() , ans.end());
        return ans;
    }
};