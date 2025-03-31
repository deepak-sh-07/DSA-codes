class Solution {
    public:
        ListNode *detectCycle(ListNode *head) {
            ListNode *slow = head;
            ListNode *fast = head;
            if(fast==NULL || fast->next==NULL) return NULL;
            while(fast && fast->next){
                slow = slow->next;
                fast = fast->next->next;
                if(slow==fast) break;
            }
            if(fast==NULL || fast->next==NULL) return NULL;
            ListNode *temp = head;
            while(temp!=slow){
                temp = temp->next;
                slow = slow->next;
            }
            return slow;
        }
    };//leetcode 142