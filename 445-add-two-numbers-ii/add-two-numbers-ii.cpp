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
   ListNode* reverse(ListNode* list){
    ListNode* curr = list;
    ListNode* prev = nullptr;
    ListNode* next = nullptr;

    while(curr != nullptr){
        next = curr ->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
   }

   void insertATtail(ListNode* &anshead, ListNode* &anstail, int value){
    ListNode* temp = new ListNode(value);

    if(anshead == nullptr){
        anshead= temp;
        anstail = temp;
        return;
    }
    else{
        anstail->next = temp;
        anstail= temp;
        return;
    }
   }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);

        ListNode* anshead= nullptr;
        ListNode* anstail = nullptr;

        int carry = 0;

        while(l1 != nullptr || l2 != nullptr || carry != 0){
        int val1=0;
        if(l1!= nullptr){
        val1= l1->val;
        }
        int val2= 0;
        if(l2 != nullptr){
            val2= l2->val;
        }
        
        int sum = val1 + val2 + carry;
        int value = sum % 10;
        insertATtail(anshead, anstail, value);
        carry = sum/10;

        if(l1) l1= l1->next;
        if(l2) l2 = l2->next;

        }

        anshead =reverse(anshead);

        return anshead;
    }
};