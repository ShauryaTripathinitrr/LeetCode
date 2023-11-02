class Solution {
private:
int countbits(int n)
{
    long long count=0;
    if(n==0 || n==1)
    {
        return n;
    }
    while(n!=0)
    {
        count+=(1&n);
        n=n>>1;
    }
    return count;
}
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>>v;
        vector<int>ans;
        for(int i=0;i<arr.size();i++)
        {
            v.push_back({countbits(arr[i]),arr[i]});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
        {
            ans.push_back(v[i].second);
        }
        return ans;
    }
};