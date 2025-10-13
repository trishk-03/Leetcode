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
   void check_pathsum(TreeNode* root, long long targetSum, int &count){
    if(root == nullptr) return;
    if(targetSum == root->val) count ++;;

    check_pathsum(root->left,targetSum - root->val, count);
    check_pathsum(root->right, targetSum- root->val, count);
    
   }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(root== nullptr) return 0;
        int count  =0;
        //this will check from the node nd it will check from the current node
        check_pathsum(root, targetSum, count);
        // this will check from the left subtree because its not neccesary that we have to find the    target sum from root only we also have to find the target sum from other nodes also because we have to return the total no of paths that will equal to the target sum 
        count+= pathSum(root->left, targetSum);
        // this will check from the right subtree 
        count+= pathSum(root->right,targetSum);
        return count;        
    }
};