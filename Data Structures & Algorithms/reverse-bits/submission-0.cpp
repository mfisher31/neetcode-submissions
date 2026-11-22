class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t out { 0 };
        for (uint32_t i = 0; i < 32; ++i) {
            if (((n >> i) & 1) > 0)
                out |= (1 << (31 - i));
        }
        return out;
    }
};
