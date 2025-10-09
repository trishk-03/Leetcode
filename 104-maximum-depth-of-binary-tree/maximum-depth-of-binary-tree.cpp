/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    int ans(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int left = ans(root->left);
        int right = ans(root->right);

        return max(left, right) + 1;
    }
public : 
    int maxDepth(TreeNode* root) {
    return ans(root);
}
};