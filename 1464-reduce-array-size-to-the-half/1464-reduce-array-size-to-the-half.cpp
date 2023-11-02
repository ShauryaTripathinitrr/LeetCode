class Solution {
public:
    int minSetSize(vector<int>& arr) {
        vector<int>v;
        map<int,int>mp;
        long long count=0;
        long long l=0;
        long long m=arr.size()/2;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]++;
        }
        for(auto i:mp)
        {
            v.push_back(i.second);
        }
        if(v.size()==1)
        {
            return 1;
        }
        sort(v.begin(),v.end());
        for(int i=v.size()-1;i>=0;i--)
        {
          count+=v[i];
           l++;
          if(count>=m)
          {
             break;
          }
        }
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
        return l;
    }
};