class Solution {
private:
    int helper(TreeNode* root, bool isLeft) {
        if (root == nullptr)
            return 0;

        // If it's a left leaf, add its value
        if (isLeft && root->left == nullptr && root->right == nullptr)
            return root->val;

        // Otherwise, continue traversal
        return helper(root->left, true) + helper(root->right, false);
    }

public:
    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root, false);
    }
};
