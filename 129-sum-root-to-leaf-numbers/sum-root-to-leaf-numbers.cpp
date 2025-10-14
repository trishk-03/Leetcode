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

        // main logic
        number = number*10 +root->val ; 

        // if there is a leaf node then it means that after this no digit will be possible to add to that number then just add it to the digit and after this recuursion will handle for the all cases 
        if(root->left == nullptr && root ->right ==nullptr){
            ans += number;
            return; 
        }
        sum_rtl(root->left,ans,number); // for left subtree
        sum_rtl(root->right, ans,number); // for right subtree
    }
public:
    int sumNumbers(TreeNode* root) {
        int ans =0;
        sum_rtl(root,ans,0);
        return ans;
    }
};