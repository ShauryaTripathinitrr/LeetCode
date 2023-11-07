class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans;
        int zemro=0;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                zemro++;
            }
        }
        if(zemro==0)
        {
            int pro=1;
            for(int i=0;i<nums.size();i++)
            {
                pro=pro*nums[i];
            }
            for(int i=0;i<nums.size();i++)
            {
                ans.push_back(pro/nums[i]);
            }
            return ans;
        }
        else if(zemro>1)
        {
            for(int i=0;i<nums.size();i++)
            {
                    ans.push_back(0);
            }
        }
        else if(zemro==1)
        {
            int pro1=1;
            for(int i=0;i<nums.size();i++)
            {
            if(nums[i]!=0)
            {
                pro1=pro1*nums[i];
            }
            }
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]==0)
                {
                    ans.push_back(pro1);
                }
                else
                {
                    ans.push_back(0);
                }
            }
        }
        return ans;
    }
};