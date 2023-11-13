class Solution {
private:
int countbits(int n)
{
    int count=0;
    if(n==0)
    {
        return 0;
    }
    while(n!=0)
    {
        count++;
        n=n>>1;
    }
    return count;
}
public:
    int bitwiseComplement(int n) {
        int kaps=countbits(n);
        int mask=1;
        for(int i=1;i<=kaps-1;i++)
        {
           mask=(mask<<1)+1;
        }
        cout<<mask<<endl;
        return mask^n;
    }
};