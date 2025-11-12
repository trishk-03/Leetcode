/*
Root has index 0
For each node with index i:
Left child → 2*i + 1
Right child → 2*i + 2

For each level, width = (last_index - first_index) + 1
*/
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
        long long maxWidth = 0;
        queue<pair<TreeNode*, long long>> q; // node + index
        q.push({root, 0});
        
        while (!q.empty()) {
            int size = q.size();
            long long start = q.front().second;
            long long end = q.back().second;
            maxWidth = max(maxWidth, end - start + 1);
            
            for (int i = 0; i < size; i++) {
                auto [node, index] = q.front();
                q.pop();
                
                // Normalize index to avoid overflow
                long long currIndex = index - start;
                
                if (node->left)
                    q.push({node->left, currIndex * 2 + 1});
                if (node->right)
                    q.push({node->right, currIndex * 2 + 2});
            }
        }
        
        return (int)maxWidth;
    }
};
