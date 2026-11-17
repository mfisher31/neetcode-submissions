class Deque {
public:
    Deque() {
        left.next = &right;
        right.prev = &left;
    }

    ~Deque() {
        auto it = left.next;
        while (it != &right) {
            auto next = it->next;
            delete it;
            it = next;
        }
    }

    constexpr bool isEmpty() const noexcept {
        return left.next == &right;
    }

    void append(int value) {
        auto node = new Node { value };
        auto prev = right.prev;
        prev->next = node;
        node->prev = prev;
        node->next = &right;
        right.prev = node;
    }

    void appendleft(int value) {
        auto node = new Node { value };
        auto next = left.next;
        node->prev = &left;
        node->next = next;
        left.next = node;
        next->prev = node;
    }

    int pop() noexcept {
        if (isEmpty())
            return -1;

        auto old = right.prev;
        int r = old->value;
        old->prev->next = &right;
        right.prev = old->prev;
        delete old;
        return r;
    }

    int popleft() noexcept {
        if (isEmpty())
            return -1;

        auto old = left.next;
        int r = old->value;
        left.next = old->next;
        left.next->prev = &left;
        delete old;
        return r;
    }

private:
    struct Node {
        int value { 0 };
        Node* prev { nullptr };
        Node* next { nullptr };
    };

    Node left, right;
};
