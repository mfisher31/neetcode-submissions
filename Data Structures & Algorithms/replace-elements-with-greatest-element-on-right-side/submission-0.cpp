// RTL traversal
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> out (arr.size());
        int rmax = -1, i = arr.size();
        while (--i >= 0) {
            out[i] = rmax;
            rmax = std::max (rmax, arr[i]);
        }
        return out;
    }
};
