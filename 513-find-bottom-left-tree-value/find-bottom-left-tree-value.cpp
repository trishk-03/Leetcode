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
private:
    void dfs(TreeNode* root, int depth, int& maxDepth, int& leftmostVal) {
        if (!root)
            return;
        if (depth > maxDepth) {
            maxDepth = depth;
            leftmostVal = root->val;
        }
        dfs(root->left, depth + 1, maxDepth, leftmostVal);
        dfs(root->right, depth + 1, maxDepth, leftmostVal);
    }

public:
    int findBottomLeftValue(TreeNode* root) {
        int maxDepth = 0;
        int leftmostVal = root->val;
        dfs(root, 1, maxDepth, leftmostVal);
        return leftmostVal;
    }
};
