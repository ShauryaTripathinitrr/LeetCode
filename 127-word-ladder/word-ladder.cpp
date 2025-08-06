class Solution {
public:
    int ladderLength(string s, string e, vector<string>& wordList) {
        set<string>st(wordList.begin() , wordList.end());

        queue<pair<string , int>>q;
        q.push({s , 1});

        while(!q.empty()){
            int steps = q.front().second;
            string s = q.front().first;
            if(s == e){
                return steps;
            }
            q.pop();
            for(int i = 0 ; i < s.size() ; i++){
                char oo = s[i];
                for(char ch = 'a' ; ch <= 'z' ; ch++){
                    s[i] = ch;
                    if(st.find(s) != st.end()){
                        st.erase(s);
                        q.push({s , steps + 1});
                    }
                }
                s[i] = oo;
            }
        }
        return 0;
    }
};