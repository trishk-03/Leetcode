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
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newNode = new TreeNode(val);
        TreeNode* temp = root;
        if(root == nullptr) {
            root = newNode; 
            }
        while(temp!= nullptr){
            if(temp->val > val){
                if(temp->left == nullptr) {
                    temp->left = newNode;
                    break;
                    }
                temp= temp->left;
            }
            else{
                if(temp->right == nullptr){
                    temp->right = newNode;
                    break;
                }
                temp = temp->right;
            }
        }
        return root;

    }
};