class Solution {
private:
bool binary(vector<int>& nums, int target)
{
    int low=0;
    int high=nums.size()-1;
    while(low <= high)
    {
        int mid=low+(high-low)/2;

        if(nums[mid]==target)
        {
            return true;
        }
        if(nums[mid]==nums[low] && nums[mid]==nums[high])
        {
            low++;
            high--;
            continue;
        }
        if(nums[low]<=nums[mid])
        {
            if(nums[low]<=target && nums[mid]>=target)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        else
        {
            if(nums[mid]<=target && nums[high]>=target)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
    }
    return false;
}
public:
    bool search(vector<int>& nums, int target) {
        return binary(nums,target);
    }
};