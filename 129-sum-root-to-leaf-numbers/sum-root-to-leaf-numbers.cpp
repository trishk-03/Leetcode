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
    void sum_rtl(TreeNode* root, int &ans, int number){
        if(root ==  nullptr) return;
        number = number*10 +root->val ; 
        

        if(root->left == nullptr && root ->right ==nullptr){
            ans += number;
            return; 
        }
        sum_rtl(root->left,ans,number);
        sum_rtl(root->right, ans,number);
    }
public:
    int sumNumbers(TreeNode* root) {
        int ans =0;
        sum_rtl(root,ans,0);
        return ans;
    }
};