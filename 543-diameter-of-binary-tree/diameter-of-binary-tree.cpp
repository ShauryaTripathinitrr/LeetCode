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
int find_it_baby(TreeNode* root,int &maxi){
    if(root==NULL)return 0;

    int high=find_it_baby(root->left,maxi);
    int low=find_it_baby(root->right,maxi);

    maxi=max(maxi,high+low);

    return 1+max(high,low);
}
public:
    int diameterOfBinaryTree(TreeNode* root)
    {
         int maxi=INT_MIN;
         find_it_baby(root,maxi);
        return maxi;
    }
};