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
struct NodeInfo
{
    bool isBST;
    int mini;
    int maxi;
    int sum;
};
int ans=0;

    int maxSumBST(TreeNode* root) {
        solve(root);
    return ans;
    }

    NodeInfo solve(TreeNode* root)
    {
        if(!root)return {true,INT_MAX,INT_MIN,0};

        NodeInfo left = solve(root->left);
        NodeInfo right = solve(root->right);

        if(left.isBST && right.isBST &&
           left.maxi < root->val && root->val < right.mini)
        {
            int curSum = root->val+left.sum+right.sum;
            ans=max(ans,curSum);
            return {true,min(root->val,left.mini),max(root->val,right.maxi) ,curSum};
        }   
    return {false,INT_MIN,INT_MAX,0};
    }
};