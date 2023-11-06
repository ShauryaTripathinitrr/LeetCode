class Solution {
private:
int countbits(int n)
{
    int count=0;
    while(n!=0)
    {
        count++;
        n=n>>1;
    }
    return count;
}
public:
    int binaryGap(int n)
    {
        int kaps=countbits(n);
        int maxi=INT_MIN;
        vector<int>ans;
        for(int i=0;i<kaps;i++)
        {
            int bit=1&(n>>i);
            if(bit==1)
            {
                ans.push_back(i);
            }
        }
        for(int i=0;i<ans.size()-1;i++)
        {
            int diff=abs(ans[i]-ans[i+1]);
            maxi=max(maxi,diff);
        }
        if(maxi==INT_MIN)
        {
            return 0;
        }
        return maxi;
    }
};