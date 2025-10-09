/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* buildBST(vector<int>v, int l, int r){
        if(l>r) return nullptr;
        int mid = l+(r-l)/2;

        TreeNode* root = new TreeNode(v[mid]);
        root->left = buildBST(v, l, mid - 1);
        root->right = buildBST(v, mid + 1, r);

        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
    vector<int> v;
    ListNode* temp = head;
    while(temp != nullptr){
        v.push_back(temp->val);
        temp = temp->next;
    }
    return buildBST(v, 0, v.size() - 1);
    }
};