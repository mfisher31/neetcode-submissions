class LinkedList {
public:
    LinkedList() {

    }

    int get(int index) {
        if (index < 0 || index >= _size)
            return -1;

        auto it = _head;
        while (it != nullptr) {
            if (index == 0)
                return it->value;
            --index;
            it = it->next;
        }

        return -1;
    }

    void insertHead (int val) {
        auto item = new Node { val };
        if (_head == nullptr) {
            _head = item;
        } else {
            item->next = _head;
            _head = item;
        }
        if (_tail == nullptr)
            _tail = _head;
        ++_size;
    }
    
    void insertTail(int val) {
        auto item = new Node { val };
        if (_tail == nullptr) {
            _head = _tail = item;
        } else {
            _tail->next = item;
            _tail = item;
        }
        ++_size;
    }

    bool remove(int index) {
        if (index < 0 || index >= _size)
            return false;
        
        auto it = _head;
        Node* prev { nullptr };
        while (it != nullptr) {
            if (index == 0) {
                if (prev) {
                    prev->next = it->next;
                    if (it == _tail)
                        _tail = prev;
                } else {
                    _head = it->next;
                }
                delete it;
                break;
            }
            --index;
            prev = it;
            it = it->next;
        }

        if (_size == 1) {
            _head = _tail = nullptr;
        }

        --_size;
        return true;
    }

    vector<int> getValues() {
        vector<int> out;
        auto it = _head;
        while (it != nullptr) {
            out.emplace_back (it->value);
            it = it->next;
        }
        return out;
    }
private:
    struct Node {
        int value { 0 };
        Node* next { nullptr };
    };

    Node* _head = nullptr;
    Node* _tail = nullptr;
    int _size { 0 };
};