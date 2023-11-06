class Solution {
private:
    int countbits(int n)
    {
        int count=0;

        while(n!=0)
        {
            count+=1&n;
            n=n>>1;
        }
        return count;
    }
    bool prime(int n)
    {
        if(n==2)
        {
            return true;
        }
        if(n==1)
        return false;
        
        for(int i=2;i<n;i++)
        {
            if(n%i==0)
            {
                return false;
            }
        }
        return true;
    }
public:
    int countPrimeSetBits(int left, int right)
    {
        vector<int>ans;
        for(int i=left;i<=right;i++)
        {
            ans.push_back(countbits(i));
        }
        int dont=0;
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<ans.size();i++)
        {
            if(prime(ans[i]))
            {
                dont++;
            }
        }
        return dont;
    }
};