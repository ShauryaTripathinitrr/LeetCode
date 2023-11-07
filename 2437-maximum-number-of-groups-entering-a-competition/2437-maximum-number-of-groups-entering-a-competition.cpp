class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int grps=0;
        sort(grades.begin(),grades.end());
        int n=grades.size();
        int i=0;
        for(int i=1;i<=n;i++)
        {
            n=n-i;
            if(n>=0)
            {
                grps++;
            }
            if(n<0)
            {
                break;
            }
        }
        return grps;
    }
};