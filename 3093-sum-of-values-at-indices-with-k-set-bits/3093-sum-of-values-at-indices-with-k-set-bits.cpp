class Solution {
private:
int count_set(int n)
{
    long long count=0;
     if(n==0 || n==1)
     {
         return n;
     }
     while(n!=0)
     {
         count+=(1&n);
         n=n>>1;
     }
     return count;
}
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int n=nums.size();
        long long sum=0;
        for(int i=0;i<n;i++)
        {
         long long j=count_set(i);
         if(j==k)
         sum+=nums[i];
        }
        return sum;
    }
};