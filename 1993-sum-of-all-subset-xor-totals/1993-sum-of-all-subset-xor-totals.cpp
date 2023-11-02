class Solution {
void generate(vector<int>nums,vector<vector<int>>&v,vector<int>out,int index)
{
   if(index>=nums.size())
   {
       v.push_back(out);
       return;
   }
   generate(nums,v,out,index+1);

   int element=nums[index];
   out.push_back(element);
   generate(nums,v,out,index+1);
}
public:
    int subsetXORSum(vector<int>& nums)
    {
        vector<vector<int>>v;
        vector<int>out;
        vector<int>jap;
        int index=0;
        generate(nums,v,out,index);
        long long k=0;
        long long sum=0;
        for(int i=0;i<v.size();i++)
        {
            for(int j=0;j<v[i].size();j++)
            {
             cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
        for(int i=0;i<v.size();i++)
        {
            for(int j=0;j<v[i].size();j++)
            {
              k=k^v[i][j];
              cout<<k<<" ";
            }
            sum+=k;
            jap.push_back(sum);
            k=0;
            sum=0;
        }
         cout<<endl;
         sum=0;
         for(int i=0;i<jap.size();i++)
         {
             sum+=jap[i];
         }
        return sum;
    }
};