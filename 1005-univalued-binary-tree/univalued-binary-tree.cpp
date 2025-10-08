class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if (root == nullptr)
            return true;

        // If left child exists and its value differs
        if (root->left && root->left->val != root->val)
            return false;

        // If right child exists and its value differs
        if (root->right && root->right->val != root->val)
            return false;

        // Recursively check left and right subtrees
        return isUnivalTree(root->left) && isUnivalTree(root->right);
    }
};
