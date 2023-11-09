class Solution {
private:
int binary(vector<int>& nums, int target)
{
    int low=0;
    int high=nums.size()-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(nums[mid]==target)
        {
            return mid;
        }
        //left sorted
        else if(nums[low]<=nums[mid])
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
        //right sorted
        else
        {
            if(nums[mid]<=target&&nums[high]>=target)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
    }
    return -1;
}
public:
    int search(vector<int>& nums, int target) {
        return binary(nums,target);
    }
};