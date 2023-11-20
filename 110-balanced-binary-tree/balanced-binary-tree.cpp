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
  int heights(TreeNode* &root)
  {
      if(root==NULL)
      {
          return 0;
      }

      int leftheight=heights(root->left);
      int rightheight=heights(root->right);

      if(leftheight==-1 || rightheight==-1)
      {
          return -1;
      }

      if(abs(leftheight-rightheight)>1)
      {
          return -1;
      }
      return max(leftheight,rightheight)+1;
  }
public:
    bool isBalanced(TreeNode* root)
    {
        int k=heights(root);

        if(k==-1)
        {
            return false;
        }
        else
        {
            return true;
        }

    }
};