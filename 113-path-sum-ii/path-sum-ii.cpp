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
    void check_sum(TreeNode* root, int target,vector<vector<int>>&result,vector<int>&ans){
      if(root == nullptr) return;

      ans.push_back(root->val);

      if(root->left == nullptr && root->right == nullptr && target == root->val){
      result.push_back(ans);
      }
      check_sum(root->left , target-root->val, result,ans);
      check_sum(root->right , target - root->val, result,ans);
      ans.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> ans;

        check_sum(root, targetSum, result,ans);
        return result;
    }
};