class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        if(nums.size()==2 && nums[0]<0)
        {
            swap(nums[0],nums[n-1]);
            return nums;
        }
        if(nums.size()==2 && nums[0]>0)
        {
            return nums;
        }
        vector<int>pos;
        vector<int>neg;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                pos.push_back(nums[i]);
            }
            else
            {
                neg.push_back(nums[i]);
            }
        }
        int k=0;
        int j=0;
        for(int i=0;i<n;i++)
        {
            if(!(i&1))
            {
                ans.push_back(pos[k]);
                k++;
            }
            else
            {
                ans.push_back(neg[j]);
                j++;
            }
        }
        return ans;
    }
};