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
    bool hasAlternatingBits(int n)
    {
        int kaps=countbits(n);
        vector<int>ans;
        int ones=0;
        int zeros=0;

        if(kaps==1)
        {
            return true;
        }
        for(int i=0;i<kaps;i++)
        {
            int bit=n&1;
            n=n>>1;
            ans.push_back(bit);
        }
        for(int i=0;i<ans.size()-1;i++)
        {
            if(ans[i]==ans[i+1])
            {
                return false;
            }
        }
        return true;
    }
};