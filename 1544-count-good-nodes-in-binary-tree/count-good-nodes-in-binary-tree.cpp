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
    void dfs(TreeNode* root, int &ans, int m){
        if(root == nullptr) return;
        // if(root->val < m) return;

        if(root->val >= m) ans++;
        m = max(root->val,m);
        dfs(root->left, ans, m);
        dfs(root->right , ans ,m);
    }
public:
    int goodNodes(TreeNode* root) {
        int ans =0;
        dfs(root,ans,root->val);
        return ans;
    }
};