/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    int find_max_index(int start, int end, vector<int>& nums) {
        int idx = start;
        for (int i = start; i <= end; i++) {
            if (nums[i] > nums[idx]) {
                idx = i;
            }
        }
        return idx;
    }

    TreeNode* buildTree(vector<int>& nums, int start, int end) {
        if (start > end) return nullptr;

        int maxIndex = find_max_index(start, end, nums);
        TreeNode* root = new TreeNode(nums[maxIndex]);

        // recursively build left and right subtrees
        root->left = buildTree(nums, start, maxIndex - 1);
        root->right = buildTree(nums, maxIndex + 1, end);

        return root;
    }

public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildTree(nums, 0, nums.size() - 1);
    }
};
