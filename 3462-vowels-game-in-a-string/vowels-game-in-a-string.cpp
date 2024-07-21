class Solution {
private:
bool isVowel(char ch)
{
    return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
}
public:
    bool doesAliceWin(string s) 
    {
        int cntfreq=0;
        
        for(auto it:s)
        {
            if(isVowel(it))
            {
                cntfreq++;
            }
        }
        
        if(cntfreq%2==0)
        {
            if(cntfreq==0)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        else
        {
            return true;
        }
        
        return false;
    }
};