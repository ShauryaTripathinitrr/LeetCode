class Solution {
public:
    int rangeBitwiseAnd(int l, int r) {
        long i=0,j,s=INT_MAX;
        if(l==r) return l;
        while(pow(2,i)<=r)
        {
            if(pow(2,i)>=l and pow(2,i)<=r and pow(2,i)-1>=l) return 0;
            i++;
        }
        for(j=l;j<=r;j++)
            {
                s=s&j;   
            }
        return s;
    }
};