class Solution {
    public:
        ListNode* reverse(ListNode* head){
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
        ListNode* reverseBetween(ListNode* head, int left, int right) {
            int count = 1;
            ListNode* a =NULL;
            ListNode* b =NULL;
            ListNode* c =NULL;
            ListNode* d =NULL;
            if(left==right) return head;
            ListNode* temp = head;
            while(count<=right){
                if(count==left) b = temp;
                if(count+1==left){
                    a = temp;
                    b = temp->next;
                }
                if(count==right){
                    c = temp;
                    d = temp->next;
                    c->next = NULL;
                }
                count++;
                temp = temp->next;
            }
            c = reverse(b);
            if(a==NULL) head = c;
            else  a->next = c;
            b->next = d;
            return head;
        }
    };//92