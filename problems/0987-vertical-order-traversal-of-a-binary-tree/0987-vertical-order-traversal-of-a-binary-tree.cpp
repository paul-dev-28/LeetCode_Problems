class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            TreeNode *node=it.first;
            int x=it.second.first;
            int y=it.second.second;
            mp[x][y].insert(node->val);
            if(node->left)
                q.push({node->left,{x-1,y+1}});
            if(node->right)
                q.push({node->right,{x+1,y+1}});
        }
        vector<vector<int>> ans;
        for(auto &i:mp)
        {
            vector<int> v;
            for(auto &j:i.second)
            {
                for(auto &k:j.second)
                    v.push_back(k);
            }
            ans.push_back(v);
        }
        return ans;
    }
};