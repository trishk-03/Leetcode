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
    int maxLevelSum(TreeNode* root) {
        if(!root) return 0;
        int maxsum = INT_MIN;
        int level = 1;
        int max_level =1;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
           int size = q.size();
           int curr_sum = 0;

           for(int i =0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                curr_sum += node->val;

                 if(node->left != nullptr) q.push(node->left);
                 if(node->right != nullptr) q.push(node->right);
 
           }
            if(curr_sum>maxsum){
            maxsum = curr_sum;
            max_level = level;
          }
            level++;
        }
    return max_level;
    }
};