// one pass v1
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0, count = 0;
        for (auto n : nums) {
            count = n == 1 ? count + 1 : 0;
            max = std::max (max, count);
        }
        return max;
    }
};
