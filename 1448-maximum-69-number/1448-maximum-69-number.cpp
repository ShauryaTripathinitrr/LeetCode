class Solution {
public:
    int maximum69Number (int num) {
        vector<int>v;
        while(num!=0)
        {
            int dig=num%10;
            v.push_back(dig);
            num=num/10;
        }
        reverse(v.begin(),v.end());

        for(int i=0;i<v.size();i++)
        {
            if(v[i]==6)
            {
                v[i]=9;
                break;
            }
        }
        
        int ans=0;
        int k=v.size();

        for(int i=0;i<k;i++)
        {
            ans+=v[i]*pow(10,k-i-1);
        }
        return ans;
    }
};