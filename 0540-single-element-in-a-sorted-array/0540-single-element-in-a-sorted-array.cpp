class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int xonr=0;
        for(int i=0;i<nums.size();i++)
        {
            xonr=xonr^nums[i];
        }

        return xonr;
    }
};