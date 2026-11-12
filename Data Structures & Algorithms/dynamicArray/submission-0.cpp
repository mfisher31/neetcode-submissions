class DynamicArray {
public:

    DynamicArray(int capacity)
        : _capacity(capacity) {
        _data.reset (new int[capacity]);
    }

    int get(int i) {
        return _data.get()[i];
    }

    void set(int i, int n) {
        _data.get()[i] = n;
    }

    void pushback(int n) {
        if (_size == _capacity)
            resize();
        _data.get()[_size] = n;
        ++_size;
    }

    int popback() {
        return _data.get()[--_size];
    }

    void resize() {
        _capacity *= 2;
        std::unique_ptr<int []> new_data;
        new_data.reset (new int [_capacity]);
        std::copy (_data.get(), _data.get() + _size, new_data.get());
        std::swap (_data, new_data);
    }

    int getSize() {
        return _size;
    }

    int getCapacity() {
        return _capacity;
    }

private:
    int _capacity { 0 };
    int _size { 0 };
    std::unique_ptr<int[]> _data;
};
