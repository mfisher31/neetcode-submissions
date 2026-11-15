class MyLinkedList {
public:
    MyLinkedList() {}
    
    constexpr int get(int index) const noexcept {
        if (auto it = find (index))
            return it->value;
        return -1;
    }
    
    void addAtHead(int val) {
        Node* node = new Node { val };
        if (size == 0) {
            head = tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }

        ++size;
    }
    
    void addAtTail(int val) {
        if (size == 0) {
            addAtHead (val);
            return;
        }

        auto node = new Node { val };
        tail->next = node;
        node->prev = tail;
        tail = tail->next;
        ++size;
    }
    
    void addAtIndex(int index, int val) {
        if (index <= 0) {
            addAtHead(val);
        }
        else if (size == index) {
            addAtTail (val);
        }
        else if (auto it = find (index)) {
            auto node = new Node { val };
            node->next = it;
            node->prev = it->prev;
            if (it->prev) 
                it->prev->next = node;
            it->prev = node;
            ++size;
        }
    }
    
    void deleteAtIndex(int index) {
        if (auto it = find (index)) {
            auto prev = it->prev;
            auto next = it->next;
            
            if (prev) 
                prev->next = next;
            else 
                head = next;
            
            if (next) 
                next->prev = prev;
            else 
                tail = prev;
            
            delete it;
            --size;
        }
    }

private:
    struct Node {
        int value = 0;
        Node* prev = nullptr;
        Node* next = nullptr;
    };

    Node* head { nullptr };
    Node* tail { nullptr };
    int size = 0;

    constexpr Node* find (int index) const noexcept {
        if (size == 0 || index < 0 || index >= size)
            return nullptr;
        
        auto it = head;
        while (it != nullptr) {
            if (index == 0) {
                return it;
            }
            --index;
            it = it->next;
        }

        return nullptr;
    }
};