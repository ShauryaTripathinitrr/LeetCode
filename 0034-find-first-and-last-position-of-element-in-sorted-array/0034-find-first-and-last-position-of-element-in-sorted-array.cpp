class Solution {
private:
int lower_bound(vector<int>& nums, int target)
{
    int low=0;
    int high=nums.size()-1;
    int ans=nums.size();
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(nums[mid]>=target)
        {
            ans=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return ans;
}
int upper_bound(vector<int>& nums, int target)
{
    int low=0;
    int high=nums.size()-1;
    int ans=nums.size();
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(nums[mid]>target)
        {
            ans=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return ans;
}
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb=lower_bound(nums,target);
        
        vector<int>ans;
        if(lb==nums.size() || nums[lb]!=target)
        {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        else
        {
            ans.push_back(lb);
            ans.push_back(upper_bound(nums,target)-1);
        }
        return ans;
    }
};