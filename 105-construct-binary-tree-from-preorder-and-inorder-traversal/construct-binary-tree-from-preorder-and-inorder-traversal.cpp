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
    int search(vector<int>& inorder, int start, int end, int curr){
        if(start == end) return   -1;

        for(int i = start; i<=end;i++){
            if(inorder[i] == curr)
            return i;
        }
        return -1;
    }

    TreeNode* buildTree(vector<int> & preorder, vector<int> &inorder , int &preindex,int start, int end){
      if(start> end) return nullptr;

      int curr = preorder[preindex++];
    //   preindex++;

      TreeNode* root = new TreeNode(curr);

      if(start == end) return root;

      int index = search(inorder, start, end , curr);

      root->left = buildTree(preorder, inorder, preindex, start, index-1);
      root->right = buildTree(preorder, inorder, preindex, index+1, end);

      return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preindex =0;
        return buildTree(preorder, inorder, preindex, 0, inorder.size()-1);
    }
};