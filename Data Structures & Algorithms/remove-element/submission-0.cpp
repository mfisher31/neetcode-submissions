// Using STL
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        std::erase (nums, val);
        return static_cast<int> (nums.size());
    }
};
