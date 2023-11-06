class Solution {
public:
    string largestWordCount(vector<string>& mes, vector<string>& sen) {
     
        string ans="";
        map<string, int>mp;

        for(int i=0;i<mes.size();i++){
            string s=mes[i];
            for(int j=0;j<s.size();j++){
                if(s[j]==' '){
                    mp[sen[i]]++;
                }
            }
            mp[sen[i]]++;
        }

        int maxi=INT_MIN;
        for(auto it: mp){
            if(it.second>=maxi){
                maxi=it.second;
                if(it.first>ans){
                    ans=it.first;
                }
            }
        }

        return ans;
    }
};