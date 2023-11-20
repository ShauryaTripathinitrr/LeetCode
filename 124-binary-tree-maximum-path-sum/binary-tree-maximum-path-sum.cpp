/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
int wow(TreeNode* root,int &maxi)
{
    if(root==NULL)return 0;

    int lh=max(0,wow(root->left,maxi));
    int rh=max(0,wow(root->right,maxi));
    maxi=max(maxi,(rh+lh)+root->val);

    return (root->val)+max(lh,rh);
}
public:
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        wow(root,maxi);

        return maxi;
    }
};