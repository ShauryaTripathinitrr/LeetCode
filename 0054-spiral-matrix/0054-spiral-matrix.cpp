class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int k=matrix.size()*matrix[0].size();
        int n=matrix.size();
        int m=matrix[0].size();
        int top=0;
        int bottom=n-1;
        int right=m-1;
        int left=0;
        while(top<=bottom && left<=right)
        {
             //right
        for(int i=left;i<=right;i++)
        {
            ans.push_back(matrix[top][i]);
        }
        top++;
        //bottom
        for(int i=top;i<=bottom;i++)
        {
            ans.push_back(matrix[i][right]);
        }
        right--;
        //left;
        if(top<=bottom)
        {
        for(int i=right;i>=left;i--)
        {
            ans.push_back(matrix[bottom][i]);
        }
        }
         bottom--;
        //top
        if(left<=right)
        {
         for(int i=bottom;i>=top;i--)
        {
            ans.push_back(matrix[i][left]);
        }
        }
        left++;
        }  
        return ans;     
    }
};