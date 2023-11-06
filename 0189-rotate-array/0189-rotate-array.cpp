class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        /*for(int i=0;i<k;i++)
        {
            reverse(nums.begin()+i,nums.end());
            reverse(nums.begin()+i+1,nums.end());
        }
        */
        reverse(nums.begin(),nums.begin()+(nums.size()-k));

        reverse(nums.begin()+(nums.size()-k),nums.end());
    
        reverse(nums.begin(),nums.end());
    
    }
};