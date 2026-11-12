// One pass
class Solution {
public:
    Solution() {
        _table.reserve(16);
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < (int)nums.size(); ++i) {
            const int compliment = target - nums[i];
            const auto it = _table.find (compliment);
            if (it != _table.end()) {
                return {
                    std::min((int)i, it->second),
                    std::max((int)i, it->second)
                };
            }
            _table[nums[i]] = i;
        }
    }
private:
    std::unordered_map<int, int> _table;
};
