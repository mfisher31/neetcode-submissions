class Solution {
public:
    bool validChar (char c) const {
        return (c >= 'A' && c <= 'Z' ||
               c >= 'a' && c <= 'z' ||
               c >= '0' && c <= '9');
    }
    bool isPalindrome(string s) {
        int a = 0, b = (int)s.size() - 1;
        while (a < b) {
            while (a < b && !validChar(s[a]))
                ++a;
            while (b > a && !validChar(s[b]))
                --b;
            if (std::tolower(s[a]) != std::tolower(s[b]))
                return false;
            ++a; --b;
        }
        return true;
    }
};
