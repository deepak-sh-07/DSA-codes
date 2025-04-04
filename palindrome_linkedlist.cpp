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
        bool isPalindrome(ListNode* head) {
            ListNode* slow=head;
            ListNode* fast=head;
            while(fast->next && fast->next->next){
                slow = slow->next;
                fast = fast->next->next;
            }
            ListNode* a = slow->next;
            slow->next = NULL;
            a = reverseList(a);
            ListNode* temp = a;
            while(temp){
                if(temp->val!=head->val) return false;
                temp = temp->next;
                head = head->next;
            }
            return true;
        }
    };//234