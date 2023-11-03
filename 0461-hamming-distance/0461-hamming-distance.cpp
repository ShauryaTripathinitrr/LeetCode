class Solution {
public:
    int hammingDistance(int x, int y) {
        int j=(x^y);
        int count=0;
        while(j!=0)
        {
            count+=1&j;
            j=j>>1;
        }
        return count;
    }
};