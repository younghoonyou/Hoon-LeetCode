class Node{
public:
    string word;
    Node *next = nullptr;
    Node *prev = nullptr;
    int val;
    Node(string str) : val(1), word(str){}
    Node():val(0), word(""){}
};
class AllOne {
private:
    unordered_map<string, Node*> m;
    Node *head;
    Node *tail;
public:
    AllOne() {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    
    void inc(string key) {
        Node *node = nullptr;
        if(m.find(key) != m.end()){
            node = m[key];
            node->val++;
            if(node->next == tail) return;
            Node *temp = node;
            while(temp->next != tail && node->val > temp->next->val){
                temp = temp->next;
            }
            if(temp == node) return;
            Node *curr = node->prev;
            curr->next = node->next;
            node->next->prev = curr;
            node->next = temp->next;
            temp->next->prev = node;
            temp->next = node;
            node->prev = temp;
        } 
        else{ // create new node
            node = new Node(key);
            Node *curr = head->next;
            curr->prev = node;
            node->next = curr;
            node->prev = head;
            head->next = node;
            m[key] = node;
        }
    }
    
    void dec(string key) {
        Node *node = nullptr;
        if(m.find(key) == m.end()) return;
        node = m[key];
        node->val--;
        if(node->val == 0){ // delete from list
            Node *curr = node->prev;
            curr->next = node->next;
            node->next->prev = curr;
            delete node;
            m.erase(key);
        }
        else{ // move
            Node *temp = node;
            while(temp->prev != head && node->val < temp->prev->val){
                temp = temp->prev;
            }
            if(temp == node) return;
            Node *curr = node->next;
            curr->prev = node->prev;
            node->prev->next = curr;
            node->prev = temp->prev;
            temp->prev->next = node;
            temp->prev = node;
            node->next = temp;
        }
    }
    
    string getMaxKey() {
        return tail->prev->word;
    }
    
    string getMinKey() {
        return head->next->word;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
 // code(1) goodbye(1) leet(2) hello(2)