class Solution {
private:
int countbits(int n)
{
    int count=0;
    while(n>0)
    {
        count++;
        n=n>>1;
    }
    return count;
}
public:
    int findComplement(int num) {
       int kaps=countbits(num);
        int k=0;
       for(int i=0;i<kaps;i++)
       {
           num=num^(1<<i);
       }
       return num;
    }
};