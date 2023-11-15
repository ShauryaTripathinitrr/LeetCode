class Solution {
public:
    int minSteps(string s, string t) {
        int count=0;
        if(s==t)return 0;
        map<char,int>mp1,mp2;
        for(int i=0;i<s.length();i++)
        {
            mp1[s[i]]++;
        }
        for(auto i:t)
        {
            mp2[i]++;
        }
        int a;
        for(auto i:mp1)
        {
            if(mp2.find(i.first)!=mp2.end())
            {
                if(i.second>mp2[i.first])
                {
                    a=i.second-mp2[i.first];
                }
                else
                {
                    continue;
                }
            }
            else
            {
                a=i.second;
            }
            count+=a;
        }
        return count;
    }
};