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
    unordered_map<int,int> mp;
    TreeNode* build(vector<int> &preorder,vector<int> &inorder,
                    int ps,int pe,int is,int ie)
    {
        if(ps>pe || is>ie)
            return NULL;
        TreeNode* root=new TreeNode(preorder[ps]);
        int idx=mp[root->val];
        int left=idx-is;
        root->left=build(preorder,inorder,
                         ps+1,
                         ps+left,
                         is,
                         idx-1);
        root->right=build(preorder,inorder,
                          ps+left+1,
                          pe,
                          idx+1,
                          ie);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       for(int i=0;i<inorder.size();i++)
            mp[inorder[i]]=i;
        return build(preorder,inorder,
                     0,
                     preorder.size()-1,
                     0,
                     inorder.size()-1);
    }
};