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
    int height(TreeNode* root){
        if(root == nullptr) return 0;
        int left = height(root->left);
        int right = height(root->right);

        return max(left,right)+1;
    }
    void deepest_sum(TreeNode* root, int & ans, int  target ,int curr_height){
        if(root == nullptr) return;
        if(curr_height == target){
        ans += root->val;
        return;
        }
    
        deepest_sum(root->left, ans, target, curr_height + 1);
        deepest_sum(root->right, ans, target, curr_height +1);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        int ans =0;
        int target = height(root);
        deepest_sum(root , ans ,target,1);
        return ans;
    }
};