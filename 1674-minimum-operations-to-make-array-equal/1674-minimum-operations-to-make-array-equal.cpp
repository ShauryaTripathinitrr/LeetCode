class Solution {
public:
    int minOperations(int n)
    {
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            v.push_back((2*i)+1);
        }
        int i=0;
        int j=n-1;
        int op=0;
        while(i<j)
        {
          int avg=(v[i]+v[j])/2;
          int sub=avg-v[i];
          op+=sub;
          i++;
          j--;
        }
        return op;
    }
};