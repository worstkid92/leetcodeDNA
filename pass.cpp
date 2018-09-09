class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> res;
        unordered_set<int> st;
        unordered_map<int, int> m{{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        int cur = 0, i = 0;
        while (i < 9) cur = cur << 2 | m[s[i++]];
        while (i < s.size()) {
            cur = ((cur & 0x3ffff) << 2) | (m[s[i++]]);
            if (st.count(cur)) res.insert(s.substr(i - 10, 10));
            else st.insert(cur);
        }
        return vector<string>(res.begin(), res.end());
    }
};