class Solution {
private:
int revermse(int n)
{
    int rev=0;
    while(n!=0)
    {
        int dig=n%10;
        rev=rev*10+dig;
        n=n/10;
    }
    return rev;
}
public:
    int countDistinctIntegers(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[revermse(nums[i])]++;
            mp[nums[i]]++;
        }
        return mp.size();
    }
};