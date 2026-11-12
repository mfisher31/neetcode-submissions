class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (size_t i = 0; i < nums.size(); ++i)
            _table[nums[i]] = i;
        for (size_t i = 0; i < nums.size(); ++i) {
            const int compliment = target - nums[i];
            const auto it = _table.find (compliment);
            if (it != _table.end() && (int)i != it->second) {
                return {
                    std::min((int)i, it->second),
                    std::max((int)i, it->second)
                };
            }
        }

        return {};
    }

private:
    std::unordered_map<int, int> _table;
};
