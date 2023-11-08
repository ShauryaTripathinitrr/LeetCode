class Solution {
bool solve(string &s,string &t)
{
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    if(s.size()!=t.size())
    {
        return false;
    }
    int count=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>t[i])
        {
            count++;
        }
    }
    if(count==0 || count==t.size())
    {
        return true;
    }
    return false;
}
public:
    bool checkIfCanBreak(string s1, string s2) {
        return (solve(s1,s2)|solve(s2,s1));
    }
};