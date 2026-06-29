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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> post;
        stack<TreeNode*> st;
        TreeNode *last=NULL;
        while(root!=NULL || !st.empty())
        {
            while(root!=NULL)
            {
                st.push(root);
                root=root->left;
            }
            root=st.top();
            if(root->right!=NULL && last!=root->right)
                root=root->right;
            else
            {
                post.push_back(root->val);
                last=root;
                st.pop();
                root=NULL;
            }
        }
        return post;
    }
};