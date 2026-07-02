/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    string serialize(TreeNode* root)
    {
        if(root==NULL)
            return "";
        queue<TreeNode*> q;
        q.push(root);
        string s="";
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            if(node==NULL)
            {
                s+="N ";
                continue;
            }
            s+=to_string(node->val)+" ";
            q.push(node->left);
            q.push(node->right);
        }
        return s;
    }
    TreeNode* deserialize(string data)
    {
        if(data.size()==0)
            return NULL;
        stringstream ss(data);
        string str;
        ss>>str;
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            ss>>str;
            if(str!="N")
            {
                node->left=new TreeNode(stoi(str));
                q.push(node->left);
            }
            ss>>str;
            if(str!="N")
            {
                node->right=new TreeNode(stoi(str));
                q.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));