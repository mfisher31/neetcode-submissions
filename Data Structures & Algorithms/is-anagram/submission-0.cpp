class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        for (auto c : s)
            _a[c]++;
        for (auto c : t)
            _b[c]++;

        for (auto c : s) {
            if (_a[c] != _b[c])
                return false;
        }
        
        return true;
    }

private:
    std::unordered_map<char, int> _a, _b;
    
};
