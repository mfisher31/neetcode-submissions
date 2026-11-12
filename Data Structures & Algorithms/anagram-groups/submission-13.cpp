struct Key {
    Key (std::string_view str) {
        for (char c : str)
            data[c - 'a']++;
    }

    constexpr bool operator== (const Key& o) const noexcept {
        return data == o.data;
    }

    std::array<char, 26> data { 0 };
};

template<>
struct std::hash<Key> {
    std::size_t operator()(const Key& obj) const noexcept {
        std::hash<string_view> hasher;
        std::string_view view { 
            static_cast<const char*> (obj.data.data()),
            obj.data.size() 
        };
        return hasher (view);
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        for (const auto& str : strs) {
            Key key (str);
            _table[key].push_back(str);
        }

        vector<vector<string>> out;
        for (const auto& it : _table)
            out.push_back (it.second);

        return out;
    }

private:
    std::unordered_map<Key, vector<string>> _table;
};
