class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int>v(n);
        int k=0;
        for(int i=0;i<n;i++)
        {
            v[i]=start+2*i;
            k=k^v[i];
        }
        return k;
    }
};