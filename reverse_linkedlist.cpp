
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
    };//206