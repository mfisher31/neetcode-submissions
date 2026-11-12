class Solution {
public:
    using Key = string;
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        for (const auto& str : strs) {
            Key key (26, 0);
            for (char c : str)
                key[c - 'a']++;
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
