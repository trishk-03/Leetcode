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
      int traverse(TreeNode* temp,int  low , int high){
        int sum =0;
        if(temp == nullptr)
        return sum;
        if(temp->val>= low && temp->val <=high)
        sum += temp->val;
        if(temp->val >low)
        sum += traverse(temp->left,low,high);
        if(temp->val< high)
        sum += traverse(temp->right,low,high);
        return sum;
      }    
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        TreeNode* temp = root;
        return traverse(temp,low,high);
    }
};