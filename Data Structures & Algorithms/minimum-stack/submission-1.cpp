class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        _data.emplace_back (val);
        if (_data.size() == 1) {
            _min.emplace_back (val);
        } else {
            _min.emplace_back (std::min (_min.back(), val));
        }
    }
    
    void pop() {
        _min.pop_back();
        _data.pop_back();
    }
    
    int top() {
        return _data.back();
    }
    
    int getMin() {
        return _min.back();
    }

private:
    std::vector<int> _data;
    std::vector<int> _min;
};
