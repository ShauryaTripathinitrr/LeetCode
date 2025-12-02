class Solution {
public:
    int maxDistinct(string s) {
        set<char>st(s.begin() , s.end());

        return st.size();
    }
};