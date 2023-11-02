class Solution {
    private:
int countbits(int n)
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
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++)
        {
            ans.push_back(countbits(i));
        }
        return ans;
    }
};