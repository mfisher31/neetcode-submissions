class Solution {
public:
    bool isInt (std::string_view op) {
        for (auto c : op) {
            if (! ((c >= '0' && c <= '9') || c == '-'))
                return false;
        }
        return true;
    }
    int calPoints(vector<string>& operations) {
        std::vector<int> out;
        
        for (const auto& op : operations) {
            if (isInt (op)) {
                int val { 0 };
                std::from_chars (op.data(), op.data() + op.size(), val);
                out.push_back (val);
            } else if (op == "D") {
                out.push_back (out.back() * 2);
            } else if (op == "+") {
                out.push_back (out[out.size() - 2] + out[out.size() -1]);
            } else if (op == "C") {
                out.pop_back();
            }
        }

        int total { 0 };
        for (const auto i : out) {
            total += i;
        }
        return total;
    }
};