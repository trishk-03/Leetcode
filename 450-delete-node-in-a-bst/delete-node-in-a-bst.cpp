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
    // Find minimum node in subtree (used to find successor)
    TreeNode* findMin(TreeNode* root) {
        while (root && root->left){ 
            root = root->left;
        }
        return root;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // found node to delete
            if (!root->left && !root->right) { // no children
                delete root;
                return nullptr;
            } else if (!root->left) { // only right child
                TreeNode* r = root->right;
                delete root;
                return r;
            } else if (!root->right) {// only left child
                TreeNode* l = root->left;
                delete root;
                return l;
            } else {  // two children: replace with successor (min in right subtree)
                TreeNode* succ = findMin(root->right);
                root->val = succ->val;
                // remove successor node from right subtree
                root->right = deleteNode(root->right, succ->val);
            }
        }
        return root;
    }
};
