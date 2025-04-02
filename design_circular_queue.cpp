class MyCircularQueue {
    public:
        class Node{
            public:
            int val;
            Node* next;
            Node* prev;
            Node(int val){
                this->val = val;
                next= NULL;
                prev = NULL;
            }
        };
        Node* list = new Node(-1);
        Node* temp = list;
        int size;
        int initial = 0;
        MyCircularQueue(int k) {
            size=k;
        }
        
        bool enQueue(int value) {
            if(initial==size) return false;
            Node* newnode = new Node(value);
            temp->next = newnode;
            newnode->prev = temp;
            temp = temp->next;
            initial++;
            return true;
        }
        
        bool deQueue() {
           if(initial==0) return false;
           list = list->next;
           list->prev=NULL;
           initial--; 
           return true;
        }
        
        int Front() {
           if(initial==0) return -1;
           return list->next->val; 
        }
        
        int Rear() {
            if(initial==0) return -1;
            return temp->val;
        }
        
        bool isEmpty() {
           if(initial==0) return true;  
           return false;
        }
        
        bool isFull() {
            if(initial==size) return true;  
           return false;
        }
    };
    
    