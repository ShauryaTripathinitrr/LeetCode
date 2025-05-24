class Solution {
public:
    vector<int> findWordsContaining(vector<string>& w, char x) {
        vector<int>ans;
        
        for(int i=0;i<w.size();i++){
            string s=w[i];
            for(int j=0;j<s.size();j++){
                if(s[j]==x){
                    ans.push_back(i);
                    break;
                }
            }
        }
        
        return ans;
    }
};