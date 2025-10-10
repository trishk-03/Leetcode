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
    TreeNode* bst(vector<int> &v, int l , int r){
        if(l>r)  return nullptr;
        int mid = l +(r-l)/2;
        TreeNode* root = new TreeNode(v[mid]);
        root->left= bst(v,l,mid-1);
        root->right = bst(v,mid+1,r);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int l =0;
        int r = nums.size()-1;
        return bst(nums , l, r);

        // first find the left and right index of an vector
        // create a function and check if l> r then return null
        // find the mid and create a root of treenode 
        // recursively find the mid for left subtree and right subtree till it reaches the bse case 
        // return the newly height balanced root subtree
    }
};