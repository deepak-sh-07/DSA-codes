
class Solution {
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
           int l1 = 0,l2=0;
           ListNode* temp1 = headA;
           ListNode* temp2 = headB;
           while(temp1!=NULL){
            l1++;
            temp1 = temp1->next;
           }
           while(temp2!=NULL){
            l2++;
            temp2 = temp2->next;
           }
           temp1 = headA;
           temp2 = headB;
           if(l1>l2){
            int diff = l1-l2;
            for(int i=1;i<=diff;i++){
                temp1 = temp1->next;
            }
            while(temp1!=temp2){
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            return temp1;
           }else{
            int diff = l2-l1;
            for(int i=1;i<=diff;i++){
                temp2 = temp2->next;
            }
            while(temp1!=temp2){
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            return temp1;
           }
        }
    };