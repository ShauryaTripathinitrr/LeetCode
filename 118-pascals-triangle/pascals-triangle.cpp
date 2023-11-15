class Solution {
private:
vector<int>Generaterows(int n)
{
    vector<int>jam;
    long long num=1;
    jam.push_back(num);
    for(int i=1;i<n;i++)
    {
        num=num*(n-i);
        num=num/i;
        jam.push_back(num);
    }
    return jam;
}
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;
        for(int i=1;i<=n;i++)
        {
            ans.push_back(Generaterows(i));
        }
        return ans;
    }
};