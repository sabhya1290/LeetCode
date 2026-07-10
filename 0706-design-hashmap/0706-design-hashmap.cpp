class MyHashMap {
    struct Node{
        int key, val;
        Node *next = nullptr;
        Node(int k, int val): key(k), val(val){};
    };

    vector<Node*> v = vector<Node*>(1000, nullptr);

    int hash(int a){
        return a%1000;
    }
public:
    MyHashMap() {
    }
    
    void put(int key, int value) {
        remove(key);
        int h = hash(key);
        if(v[h] == nullptr) v[h] = new Node(key, value);
        else{
            Node *temp = v[h];
            while(temp->next) temp = temp->next;
            temp->next = new Node(key, value);
        }
    }
    
    int get(int key) {
        int h = hash(key);
        if(v[h] == nullptr) return -1;
        Node *temp = v[h];
        while(temp){
            if(temp->key == key) return temp->val;
            temp = temp->next;
        }
        return -1;
    }
    
    void remove(int key) {
        int h = hash(key);
        if(v[h] == nullptr) return;
        if(v[h]->key == key){
            v[h] = v[h]->next;
            return;
        }
        if(!v[h]->next) return;
        Node *temp = v[h]->next, *prev = v[h];
        while(temp){
            if(temp->key == key) {
                prev->next = temp->next;
                return;
            }
            prev = prev->next;
            temp = temp->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */