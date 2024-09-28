class Node{
public:
    Node(){}
    Node(int _val):val(_val){}
    Node *next = nullptr;
    Node *prev = nullptr;
    int val = 0;
};
class MyCircularDeque {
private:
    int limit = 0;
    int cnt = 0;
    Node *head = nullptr;
    Node *tail = nullptr;
public:
    MyCircularDeque(int k) {
        head = new Node();
        tail = new Node();
        head->next = tail;
        head->prev = tail;
        tail->next = head;
        tail->prev = head;
        limit = k;
    }
    
    bool insertFront(int value) {
        if(cnt == limit) return false;
        Node *node = new Node(value);
        Node *curr = head;
        Node *exist = head->next;
        exist->prev = node;
        node->next = head->next;
        node->prev = head;
        head->next = node;
        cnt++;
        return true;
    }
    
    bool insertLast(int value) {
        if(cnt == limit) return false;
        Node *node = new Node(value);
        Node *curr = tail;
        Node *exist = tail->prev;
        exist->next = node;
        node->prev = tail->prev;
        node->next = tail;
        tail->prev = node;
        cnt++;
        return true;
    }
    
    bool deleteFront() {
        if(cnt == 0) return false;
        Node *curr = head;
        Node *exist = head->next;
        exist->next->prev = head;
        curr->next = exist->next;
        exist->next = nullptr;
        exist->prev = nullptr;
        delete exist;
        cnt--;
        return true;
    }
    
    bool deleteLast() {
        if(cnt == 0) return false;
        Node *curr = tail;
        Node *exist = tail->prev;
        exist->prev->next = tail;
        curr->prev = exist->prev;
        exist->next = nullptr;
        exist->prev = nullptr;
        delete exist;
        cnt--;
        return true;
    }
    
    int getFront() {
        if(cnt == 0) return -1;
        return head->next->val;
    }
    
    int getRear() {
        if(cnt == 0) return -1;
        return tail->prev->val;
    }
    
    bool isEmpty() {
        return (cnt == 0);
    }
    
    bool isFull() {
        return (cnt == limit);
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */