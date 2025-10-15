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
    int prevVal = -1;  
    int ans = INT_MAX; 

    void inorder(TreeNode* root) {
        if (root== nullptr)
            return;

         inorder(root->left);

          if (prevVal != -1)
          ans = min(ans, abs(root->val - prevVal));

         prevVal = root->val;
        inorder(root->right);
    }

public:
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return ans;
    }
};
