class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int>v;
        long long count=0;
        for(int i=0;i<bank.size();i++)
        {
            for(int j=0;j<bank[i].size();j++)
            {
                if(bank[i][j]=='1')
                {
                    count++;
                }
            }
            if(count>0)
            {
                v.push_back(count);
            }
            count=0;
        }
        if(v.size()==0)
        {
            return 0;
        }
        long long ans=0;
        if(v.size()==1)
        {
            return 0;
        }
        for(int i=1;i<v.size();i++)
        {
            ans+=v[i]*v[i-1];
        }
        return ans;
    }
};