class Solution {
public:
    int differenceOfSums(int n, int m) {
        long long sum1=0;
        long long sum2=0;

        for(int i=1;i<=n;i++)
        {
            if(i%m==0)
            {
                sum1+=i;
            }
            else
            {
                sum2+=i;
            }
        }
        return (sum2-sum1);
    }
};