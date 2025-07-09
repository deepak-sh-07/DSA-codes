class Node {
public:
    int val;
    Node* next;
    Node(int val, Node* next = nullptr) {
        this->val = val;
        this->next = next;
    }
};

class MyLinkedList {
public:
    Node* head;
    Node* tail;
    int size;

    MyLinkedList() {
        head = tail = nullptr;
        size = 0;
    }

    int get(int index) {
        if (index < 0 || index >= size) return -1;
        Node* temp = head;
        int i = 0;
        while (i < index) {
            temp = temp->next;
            i++;
        }
        return temp->val;
    }

    void addAtHead(int val) {
        Node* temp = new Node(val);
        if (head == nullptr) {
            head = tail = temp;
        } else {
            temp->next = head;
            head = temp;
        }
        size++;
    }

    void addAtTail(int val) {
        Node* temp = new Node(val);
        if (head == nullptr) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;

        if (index == 0) {
            addAtHead(val);
            return;
        }

        if (index == size) {
            addAtTail(val);
            return;
        }

        Node* temp = new Node(val);
        Node* t = head;
        int i = 0;
        while (i < index - 1) {
            t = t->next;
            i++;
        }
        temp->next = t->next;
        t->next = temp;
        size++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            size--;
            if (size == 0) tail = nullptr;
            return;
        }

        Node* t = head;
        int i = 0;
        while (i < index - 1) {
            t = t->next;
            i++;
        }
        Node* toDelete = t->next;
        t->next = toDelete->next;

        if (index == size - 1) {
            tail = t;
        }

        delete toDelete;
        size--;
    }
};
