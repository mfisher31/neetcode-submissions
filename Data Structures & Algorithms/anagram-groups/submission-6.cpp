struct Key {
    Key (std::string_view str) {
        for (char c : str)
            data[c - 'a']++;
    }

    constexpr bool operator== (const Key& o) const noexcept {
        return data == o.data;
    }

    std::array<int, 26> data { 0 };
};

template<>
struct std::hash<Key> {
    std::size_t operator()(const Key& obj) const noexcept {
        std::size_t seed = 0;
        std::hash<int> hasher;
        for (int i : obj.data) {
            // from boost::hash_combine formula to avoid collisions
            seed ^= hasher(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed; 
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        for (const auto& str : strs) {
            Key key (str);
            _table[key].emplace_back(str);
        }

        vector<vector<string>> out;
        for (const auto& it : _table)
            out.push_back (it.second);

        return out;
    }

private:
    std::unordered_map<Key, vector<string>> _table;
};
