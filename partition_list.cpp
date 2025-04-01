class Solution {
    public:
        ListNode* partition(ListNode* head, int x) {
            ListNode* a = new ListNode(100);
            ListNode* b = new ListNode(100);
            ListNode* tempa = a;
            ListNode* tempb = b;
            ListNode* temp = head;
            while(temp){
                if(temp->val<x){
                    tempa->next = temp;
                    tempa = temp;;
                }else{
                    tempb->next = temp;
                    tempb = temp;
                }
                temp = temp->next;
            }
            tempa->next = b->next;
            tempb->next = NULL;
            return a->next;
        }
    };