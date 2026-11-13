class Solution {
public:
    constexpr bool isOpen (char c) {
        return c == '(' || c == '{' || c == '[';
    }

    constexpr bool isClosing (char c) {
        return c == ')' || c == '}' || c == ']';
    }

    bool isValid(string s) {
        std::vector<char> stack;
        std::unordered_map<char, char> bmap {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for (char c : s) {
            if (isOpen (c)) {
                stack.push_back (c);
            } else if (isClosing (c)) {
                if (stack.empty() || stack.back() != bmap[c])
                    return false;
                stack.pop_back();
            }
        }

        return stack.empty();
    }

};
