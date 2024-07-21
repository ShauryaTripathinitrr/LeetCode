class Solution {
public:
    string losingPlayer(int x, int y) {
        string ans="";
        
        int cnt=1;
        
        while(x>=0 && y>=0)
        {
            if(x-1>=0 && y-4>=0)
            {
                x=x-1;
                y=y-4;
                cnt++;
            }
            else
            {
                if(cnt&1)
                {
                    return "Bob";
                }
                else
                {
                    return "Alice";
                }
            }
        }
        return "";
    }
};