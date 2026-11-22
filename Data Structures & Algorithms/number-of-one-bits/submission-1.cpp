class Solution {
public:
    int hammingWeight(uint32_t n) {
        std::bitset<32> bs (n);
        return static_cast<int> (bs.count());
    }
};
