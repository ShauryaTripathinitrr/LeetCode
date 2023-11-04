class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while(nums.size()!=1){
          vector<int>currvector;
          for(int i=1;i<nums.size();i++){
            currvector.push_back((nums[i]+nums[i-1])%10);
          }
          nums = currvector;
        }
        return nums[0];
    }
};