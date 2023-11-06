class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            cout<<nums[i]<<" ";
        }
        cout<<endl;
        int mini=INT_MIN;

        for(int i=0;i<nums.size()/2;i++)
        {
            int sum=nums[i]+nums[nums.size()-i-1];
            mini=max(sum,mini);
        }
        return mini;
    }
};