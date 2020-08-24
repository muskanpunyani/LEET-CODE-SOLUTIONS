/*******8
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
*****/



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
public:
    bool isLeaf(TreeNode* root)
    {
        if(root==NULL)
        {
            return false;
        }
        if(root->left==NULL && root->right==NULL)  // the node will be a leaf if it has no children
        {
            return true;
        }
        return false;
    }
    int sumOfLeftLeaves(TreeNode* root) {
          int res=0;  //answer
      if(root==NULL)
      {
          return 0;
      }
        if(isLeaf(root->left))   // if the root has left node and if that node is a leaf
       {
           res+=root->left->val;
       }
      else{
            res+=sumOfLeftLeaves(root->left);  // else recurse and find left node which is leaf
        }
        res+=sumOfLeftLeaves(root->right);   // go to right subtree of root and find the left leaf
        
        return res;
        
    }
};
