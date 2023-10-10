class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            if(mp[target-nums[i]])
            {
                ans.push_back(i);
            }
            mp[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(target-nums[ans[0]]==nums[i])
            {
                ans.push_back(i);
                break;
            }
        }

        return ans;
    }
};