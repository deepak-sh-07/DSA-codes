
class Solution {
    public:
        ListNode* merge(ListNode* l1,ListNode* l2){
            ListNode* a = l1;
            ListNode* b = l2;
            ListNode* c = new ListNode(100);
            ListNode* temp = c;
            while(a!=NULL && b!=NULL){
                if(a->val<=b->val){
                  temp->next = a;
                  a = a->next;  
                }else{
                    temp->next = b;
                    b = b->next;
                }
                temp = temp->next;
            }
            if(a==NULL) temp->next = b;
            if(b==NULL) temp->next = a;
            return c->next;
        }
        ListNode* sortList(ListNode* head) {
            if(head==NULL || head->next==NULL) return head;
            ListNode* slow = head;
            ListNode* fast = head;
            while(fast->next!=NULL && fast->next->next!=NULL){
                slow = slow->next;
                fast = fast->next->next;
            }
           ListNode* a = head; 
           ListNode* b = slow->next;
           slow->next = NULL;
           a = sortList(a);
           b = sortList(b);
          ListNode*c= merge(a,b);
           return c;
        }
    };//148