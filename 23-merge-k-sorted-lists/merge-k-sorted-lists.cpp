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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (true) {
            int smallestIdx = -1;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] == nullptr)
                    continue;
                if (smallestIdx == -1 ||
                    lists[i]->val < lists[smallestIdx]->val) {
                    smallestIdx = i;
                }
            }

            // all lists exhausted
            if (smallestIdx == -1)
                break;

            tail->next = lists[smallestIdx];
            tail = tail->next;

            lists[smallestIdx] = lists[smallestIdx]->next;
        }

        return dummy.next;
    }
};
