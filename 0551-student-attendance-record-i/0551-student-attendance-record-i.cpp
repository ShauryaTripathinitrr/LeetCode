class Solution {
public:
    bool checkRecord(string s) {
        bool count=true;
          int a=0;
          int b=0;
        for(int i=0;i<s.length();i++)
        {
          if(s[i]=='A')a++;
        }
        for(int i=0;i<s.length()-1;i++)
        {
            if(s[i]==s[i+1] && s[i]=='L')b++;
            if(s[i]!=s[i+1])b=0;

            if(b>=2)
            {
                count=false;
                break;
            }
        }
        if(a>=2)return false;

        return count;

    }
};