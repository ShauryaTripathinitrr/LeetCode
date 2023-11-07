class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>>ans;

        unordered_map<int,int>mp;
        int count=nums.size();
        int k=1;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        while(count>0)
        {
            vector<int>out;
        for(auto i:mp)
        {
            if(i.second>=k)
            out.push_back(i.first);
        }
        count=count-out.size();
        ++k;
        ans.push_back(out);
        }
        cout<<endl;
        return ans;
    }
};