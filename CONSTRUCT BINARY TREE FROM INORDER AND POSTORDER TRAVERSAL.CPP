/*Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]

Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
*/





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
    int searchit(vector<int> & inorder,int start,int end,int value)
    {
        int index;
        for(int i=start;i<=end;i++)
        {
            if(inorder[i]==value)
            {
                index=i;
                break;
            }
        }
        return index;
    }
    TreeNode* buildutil(vector<int> & inorder,vector<int>& postorder,int start,int end,int &postindex)
    {
        if(start>end)
        {
            return NULL;
        }
        TreeNode* temp=new TreeNode(postorder[postindex]);
        postindex--;
        if(start==end)
        {
            return temp;
        }
        int iindex=searchit(inorder,start,end,temp->val); //search the data in in order
        temp->right=buildutil(inorder,postorder,iindex+1,end,postindex);  // right side of index
        temp->left=buildutil(inorder,postorder,start,iindex-1,postindex);  // left side of index
        return temp;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=postorder.size(); //size of postorder array
        int m=inorder.size();  //size of inorder
        int postindex=n-1;     //taking last elem from postorder
        return buildutil(inorder,postorder,0,m-1,postindex);   
        
    }
};
