class Solution {
private:
void solver(int index,vector<int>nums,set<vector<int>>&st)
{
  if(index>=nums.size())
  {
    st.insert(nums);
    return;
  }

  for(int i=index;i<nums.size();i++)
  {
    swap(nums[i],nums[index]);
    solver(index+1,nums,st);
    swap(nums[i],nums[index]);
  }
}
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>st;
        sort(nums.begin(),nums.end());
        solver(0,nums,st);
        vector<vector<int>>ans;
        for(auto it:st)
        {
            ans.push_back(it);
        }
        return ans;
    }
};