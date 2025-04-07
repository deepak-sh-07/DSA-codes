class BrowserHistory {
    public:
        class node{
            public:
            string val;
            node* prev;
            node* next;
            node(string val){
                this->val = val;
                this->prev = NULL; 
                this->next = NULL; 
            }
        };
        node* main = new node("0");
        BrowserHistory(string homepage) {
            main->val = homepage;
        }
        void visit(string url) {
           node* newnode = new node(url);
           main->next = newnode;
           newnode->prev = main;
           main = newnode; 
        }
        string back(int steps) {
            while (main->prev != nullptr && steps--) {
                main = main->prev;
            }
            return main->val;
        }
        
        string forward(int steps) {
            while (main->next != nullptr && steps--) {
                main = main->next;
            }
            return main->val;
        }
    };//1472