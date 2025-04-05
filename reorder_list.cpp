
class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            ListNode* curr = head;
            ListNode* prev = NULL;
            ListNode* nex = NULL;
            while(curr){
                nex = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nex;
            }
            return prev;
        }
        void reorderList(ListNode* head) {
           ListNode* slow = head;
           ListNode* fast = head;  
           while(fast && fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
           }
           fast = slow->next;
           slow->next = NULL;
           slow = head;
           fast = reverseList(fast);
           ListNode* c = new ListNode(100);
           ListNode* temp = c;
           while(slow){
            temp->next = slow;
            slow = slow->next;
            temp = temp->next;
            if(fast){
            temp->next = fast;
            fast = fast->next;
            temp = temp->next;
            }
            
           }
        }
    };//143