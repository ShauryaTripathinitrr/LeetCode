class Solution {
private:
bool check(vector<int>nums,int n,int k)
{
    long long count=0;
    int bit=0;
    for(int i=0;i<nums.size();i++)
    {
       bit=(nums[i])&(1<<n);
        if(bit==1)
        {
           count++;
        }
    }
    if(count>=k)
    {
        return true;
    }
    return false;
}
public:
    int findKOr(vector<int>& nums, int k)
    {
        int sum=0;
        for(int i=0;i<32;i++){
            int c=0;
            for(int val : nums){
                if(val & (1<<i)) c++;
            }
            if(c >= k) sum += pow(2,i);
        }
        return sum;
    }
};