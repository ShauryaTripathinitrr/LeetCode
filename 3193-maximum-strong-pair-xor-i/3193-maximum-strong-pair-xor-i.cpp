class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int nas=0;
        int mini=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums.size();j++)
            {
                if(abs(nums[i]-nums[j])<=min(nums[i],nums[j]))
                {
                int kam=nums[i]^nums[j];
                mini=max(kam,mini);   
                }
            }
        }
        return mini;
    }
};