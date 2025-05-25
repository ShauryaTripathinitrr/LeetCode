class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string , int>mp;

        for(auto &i : words){
            mp[i]++;
        }

        int ans = 0;
        bool c = false;
        priority_queue<int>pq;
        for(auto it : mp){
            if(it.first[0] == it.first[1]){
                if(it.second % 2 == 0){
                    ans += it.second;
                }else{
                    pq.push(it.second);
                }
            }else if(it.first[0] != it.first[1]){
                string j = it.first;
                reverse(j.begin() , j.end());
                if(mp.find(j) != mp.end()){
                    ans += min(it.second , mp[j]) * 2;
                    mp.erase(j);
                }else{
                    continue;
                }
            }
        }
        int cnt = 0;
        while(!pq.empty()){
            if(cnt == 0){
                ans += pq.top();
                pq.pop();
                cnt = 1;
            }else{
                ans += (pq.top() - 1);
                pq.pop();
            }
        }
        return ans * 2;
    }
};