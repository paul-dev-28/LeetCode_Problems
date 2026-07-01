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
    TreeNode* build(vector<int> &postorder,vector<int> &inorder,
                    int ps,int pe,int is,int ie)
    {
        if(ps>pe || is>ie)
            return NULL;
        TreeNode* root=new TreeNode(postorder[pe]);
        int idx=mp[root->val];
        int left=idx-is;
        root->left=build(postorder,inorder,
                         ps,
                         ps+left-1,
                         is,
                         idx-1);
        root->right=build(postorder,inorder,
                          ps+left,
                          pe-1,
                          idx+1,
                          ie);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]]=i;
        return build(postorder,inorder,
                     0,
                     postorder.size()-1,
                     0,
                     inorder.size()-1);
    }
};