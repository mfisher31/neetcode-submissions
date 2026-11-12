class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> out (nums.size() * 2, 0);
        auto mid = std::copy (nums.begin(), nums.end(), out.begin());
        std::copy (nums.begin(), nums.end(), mid);
        return out;
    }
};