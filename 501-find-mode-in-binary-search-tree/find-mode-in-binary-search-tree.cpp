class Solution {
private:
    TreeNode* prev = nullptr;
    int currCount = 0;
    int maxCount = 0;
    vector<int> modes;

    void inorder(TreeNode* root) {
        if(!root) return;

        inorder(root->left);

        if(prev && prev->val == root->val) {
            currCount++;
        } else {
            currCount = 1;
        }

        if(currCount > maxCount) {
            maxCount = currCount;
            modes.clear();
            modes.push_back(root->val);
        } else if(currCount == maxCount) {
            modes.push_back(root->val);
        }

        prev = root;

        inorder(root->right);
    }

public:
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return modes;
    }
};
