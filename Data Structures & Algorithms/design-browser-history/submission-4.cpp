class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        history.reserve (100);
        history.push_back (homepage);
        size = static_cast<int> (history.size());
        index = 0;
    }
    
    void visit (string url) {
        if (index == size - 1) {
            history.push_back (std::move (url));
            ++index;
            ++size;
        } else {
            history[++index] = std::move (url);
            size = index + 1; 
        }
    }
    
    string back(int steps) {
        index = std::max (0, index - steps);
        return history[index];
    }
    
    string forward(int steps) {
        index = std::min (index + steps, size - 1);
        return history[index];
    }

private:
    vector<string> history;
    int size = 0, index = 0;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */