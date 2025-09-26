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
    int preorder(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int left = preorder(root->left);
        int right =preorder(root->right);

        if(left == 0) return right +1;
        if(right == 0) return left +1;
        
        return min (left , right)+1;
    }    
public:
    int minDepth(TreeNode* root) {
        return preorder(root);
    }

};