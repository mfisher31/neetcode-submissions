class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        for (auto n : nums) {
            if (_check.contains (n))
                return true;
            _check[n] = true;
        }
        return false;
    }

private:
    std::unordered_map<int, bool> _check;
};