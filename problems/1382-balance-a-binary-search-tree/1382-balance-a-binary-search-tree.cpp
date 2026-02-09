class Solution {
public:
    vector<TreeNode*> nodes;

    TreeNode* balanceBST(TreeNode* root) {
        extractNodes(root);
        return buildBalancedTree(0, nodes.size() - 1);
    }

private:
    void extractNodes(TreeNode* root) {
        if (!root) return;
        extractNodes(root->left);
        nodes.push_back(root);
        extractNodes(root->right);
    }

    TreeNode* buildBalancedTree(int start, int end) {
        if (start > end) return nullptr;
        int mid = start + (end - start) / 2;
        TreeNode* root = nodes[mid];
        root->left = buildBalancedTree(start, mid - 1);
        root->right = buildBalancedTree(mid + 1, end);

        return root;
    }
};