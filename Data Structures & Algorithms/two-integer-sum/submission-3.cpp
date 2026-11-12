// Sorted Solution
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> sorted;
        sorted.reserve(nums.size());
        for (int i = 0; i < nums.size(); ++i)
            sorted.push_back({ nums[i], i });
        std::ranges::sort (sorted);
        int i = 0, j = (int) nums.size() - 1;

        while (i < j) {
            const auto sum = sorted[i].first + sorted[j].first;
            if (sum == target)
                return { std::min (sorted[i].second, sorted[j].second),
                         std::max (sorted[i].second, sorted[j].second) };
            if (sum < target)
                ++i;
            else
                --j;
        }

        return {};
    }
};
