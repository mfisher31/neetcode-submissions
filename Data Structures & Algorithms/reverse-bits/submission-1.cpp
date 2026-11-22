class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        std::bitset<32> bs { n };
        std::bitset<32> out { 0 };
        for (uint32_t i = 0; i < 32; ++i) {
            out.set(31 - i, bs[i]);
        }
        return out.to_ulong();
    }
};
