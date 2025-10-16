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
    int search( int &value, vector<int>&inorder, int &start, int &end){
        for(int i =start; i<=end;i++){
            if(value == inorder[i])
            return i;
        }
        return 0;
    }
    TreeNode* Tree(vector<int> & inorder, vector<int>& postorder , int start , int end ,int & postindex){ 
        if(start>end) return nullptr;
        int value = postorder[postindex];
        postindex--;
        int index= search (value, inorder, start ,end);

        TreeNode* root = new TreeNode(value);
        
        root->right = Tree(inorder, postorder, index+1, end, postindex);
        root->left = Tree(inorder, postorder, start, index -1, postindex);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postindex = postorder.size()-1;
        return Tree(inorder, postorder, 0, inorder.size()-1,postindex);
    }
};