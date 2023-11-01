class Solution {
public:
    int minBitFlips(int start, int goal) {
        int j=(start^goal);
        int count=0;
        while(j!=0)
        {
        count+=j&1;
        j=j>>1;
        }
        return count;
    }
};