class Solution {
public:
    string minimizeStringValue(string s) {
        //har ek ques mark wale ko minimum cost wale se replace krna h 
        int n = s.length();
        map<char , int>mp;
        //pair<int , char>
        vector<pair<char , int>>was_q;
        priority_queue<pair<int , char> , vector<pair<int , char>> , greater<pair<int , char>>> pq;
        priority_queue<char , vector<char> , greater<char>>p;
        for(char ch = 'a' ; ch <= 'z' ; ch++){
            pq.push({0 , ch});
        }
        for(auto & x : s){
            mp[x]++;
        }
        string ans = "";

        for(int i = 0 ; i < n ; i++){
            if(s[i] != '?'){
                ans.push_back(s[i]);
            }else{
                while(pq.top().first != mp[pq.top().second]){
                    int a = pq.top().first;
                    char ch = pq.top().second;
                    pq.pop();
                    pq.push({mp[ch] , ch});
                }
                int a = pq.top().first;
                char ch = pq.top().second;
                pq.pop();
                ans.push_back(ch);
                was_q.push_back({ch , i});
                p.push(ch);
                mp[ch]++;
                pq.push({mp[ch] , ch});
            }
        }
        reverse(was_q.begin() , was_q.end());
        for(int i = 0 ; i < n ; i++){
            if(was_q.size() > 0 && i == was_q.back().second){
                was_q.pop_back();
                ans[i] = p.top();
                p.pop();
            }
        }
        return ans;
    }
};