class Solution {
public:
    int countDigits(int num) {
        long long count=0;
        long long kap=num;

        while(num!=0)
        {
            int dig=num%10;
            if(kap%dig==0)
            {
                count++;
            }
            num=num/10;
        }
        return count;
    }
};