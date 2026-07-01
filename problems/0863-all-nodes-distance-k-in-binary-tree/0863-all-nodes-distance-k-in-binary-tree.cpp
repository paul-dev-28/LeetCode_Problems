class Solution {
public:
    void parentmap(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            if(node->left)
            {
                parent[node->left]=node;
                q.push(node->left);
            }
            if(node->right)
            {
                parent[node->right]=node;
                q.push(node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root,TreeNode* target,int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        parentmap(root,parent);
        unordered_map<TreeNode*,bool> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target]=1;
        int dist=0;
        while(!q.empty())
        {
            if(dist==k)
                break;
            int sz=q.size();
            while(sz--)
            {
                TreeNode* node=q.front();
                q.pop();
                if(node->left && !vis[node->left])
                {
                    vis[node->left]=1;
                    q.push(node->left);
                }
                if(node->right && !vis[node->right])
                {
                    vis[node->right]=1;
                    q.push(node->right);
                }
                if(parent[node] && !vis[parent[node]])
                {
                    vis[parent[node]]=1;
                    q.push(parent[node]);
                }
            }
            dist++;
        }
        vector<int> ans;
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};