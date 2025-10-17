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
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        if(root == nullptr){
             return ans;
            }
        
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
        int max_value =INT_MIN;
        int size = q.size();
        for(int i =0 ; i<size;i++){
            TreeNode* node = q.front();
            q.pop();
            max_value = max(node->val, max_value);
            if(node->left != nullptr) q.push(node->left);
            if(node->right != nullptr) q.push(node->right);
        }
        ans.push_back(max_value);
        }
        return ans;
        
    }
};