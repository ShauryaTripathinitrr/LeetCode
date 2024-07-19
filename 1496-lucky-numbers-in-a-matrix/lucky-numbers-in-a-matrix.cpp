class Solution {
private:
bool check(int ele,int row,int col,vector<vector<int>>& mat){
    int n=mat.size();
    int m=mat[0].size();
    for(int j=0;j<m;j++)
    {
        if(mat[row][j]<ele)
        {
            return false;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(mat[i][col]>ele)
        {
            return false;
        }
    }
    return true;
}
public:
    vector<int> luckyNumbers (vector<vector<int>>& mat) {
        vector<int>ans;

        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(check(mat[i][j],i,j,mat))
                {
                    ans.push_back(mat[i][j]);
                }
            }
        }
        return ans;
    }
};