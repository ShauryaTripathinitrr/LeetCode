class Solution {
public:
    int maxOperations(string s) 
    {
        int pos=-1;
        int n=s.length();
        if(n==1)
        {
            return 0;
        }
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='1')
            {
                pos=i;
            }
        }
        if(pos==-1)
        {
            return 0;
        }
        
        int cnt=0;
        
        int j=n-1;
        while(j>=0)
        {
            if(s[j]=='0')
            {
                break;
            }
            j--;
        }
        cout<<j<<endl;
        int cnto=0;
        vector<int>kam;
        for(int i=0;i<=j;i++)
        {
            if(s[i]=='1')
            {
                cnto++;
            }
            else
            {
                if(cnto>0)
                kam.push_back(cnto);
                cnto=0;
            }
        }
        
        int h=kam.size();
        int jj=1;
        for(int i=h-1;i>=0;i--)
        {
            cout<<kam[i]<<" ";
            cnt+=(kam[i]*jj);
            jj++;
        }
        cout<<endl;
        return cnt;
    }
};