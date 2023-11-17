class Solution {
/*private:
void solve(vector<vector<int>> &ans,vector<int>output,vector<int>&v,int index)
{
    if(index>=v.size())
    {
        ans.push_back(output);
        return;
    }
    solve(ans,output,v,index+1);

    int element=v[index];
    output.push_back(element);
    solve(ans,output,v,index);
}*/

public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0;
        long long ans = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == 0){
                count++;
                ans += count;
            }
            else count = 0;
        }
        return ans;
    }
};