
class Solution {
    public:
        ListNode* oddEvenList(ListNode* head) {
            ListNode* temp=head;
            ListNode* odd = new ListNode(100);
            ListNode* even = new ListNode(100);
            ListNode* tempo = odd;
            ListNode* tempe = even;
            while(temp){
                tempo->next = temp;
                tempo = temp;
                temp = temp->next;
                if(temp==NULL) break;
                tempe->next = temp;
                tempe = temp;
                temp = temp->next;
            }
            tempe->next = NULL;
            tempo->next = even->next;
            return odd->next;
        }
    };//328