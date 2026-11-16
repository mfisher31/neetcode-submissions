class Deque {
public:
    Deque() {
        
    }

    ~Deque() {
        while (left != nullptr) {
            auto next = left->next;
            delete left;
            left = next;
        }
    }

    bool isEmpty() {
        return left == nullptr;
    }

    void append(int value) {
        auto node = new Node { value };
        if (right != nullptr) {
            node->prev = right;
            right->next = node;
            right = right->next;
        } else {
            left = right = node;
        }
    }

    void appendleft(int value) {
        auto node = new Node { value };
        if (left != nullptr) {
            node->next = left;
            left->prev = node;
            left = node;
        } else {
            left = right = node;
        }
    }

    int pop() {
        if (right == nullptr)
            return -1;
        int r = right->value;
        auto old = right;
        right = right->prev;
        if (right)
            right->next = nullptr;
        else
            left = nullptr;

        delete old;
        return r;
    }

    int popleft() {
        if (left == nullptr)
            return -1;
        
        int r = left->value;
        auto old = left;
        left = left->next;
        if (left)
            left->prev = nullptr;
        else
            right = nullptr;
        
        delete old;
        return r;
    }

private:
    struct Node { 
        int value { 0 }; 
        Node* prev { nullptr };
        Node* next { nullptr };
    };

    Node* left {nullptr};
    Node* right {nullptr};
};
