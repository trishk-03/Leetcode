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
private:
   ListNode* kthNode(ListNode* temp, int k){
    k--; // 1 index 
    while(temp!=nullptr && k>0){
        temp = temp->next;
        k--;
    }
    return temp;
   }

   ListNode* reverse(ListNode* head){
    ListNode* curr = head;
    ListNode* prev = nullptr;
    ListNode* next = nullptr;

    while(curr != nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
   }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prev = nullptr;

        while(temp!= nullptr){

            ListNode* kth = kthNode(temp,k);
            if(kth == nullptr){
                prev ->next = temp;
                break;
            }
            ListNode* newNode = kth->next;
            kth->next = nullptr;

            ListNode* reversehead =reverse(temp);
            ListNode* reversetail = temp;

            if(prev == nullptr){
                head = reversehead;
            }
            else{
                prev->next =reversehead;
            }

            prev = reversetail;
            temp = newNode;

        }
        return head;
    }
};