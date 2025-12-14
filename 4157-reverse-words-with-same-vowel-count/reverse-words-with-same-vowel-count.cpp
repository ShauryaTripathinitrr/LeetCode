class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        int n = s.length();
        int cnt = 0;
        string ans = "";
        while(s[i] != ' ' && i < n){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                cnt++;
            }
            ans += s[i];
            i++;
        }
        int j = cnt;
        cnt = 0;
        i++;
        //cout << i << " " << cnt << " " << ans << endl;
        string temp = "";
        while(i < n){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                cnt++;
            }
            if(s[i] == ' '){
                //cout << cnt << endl;
                if(cnt == j){
                    reverse(temp.begin() , temp.end());
                    ans += " ";
                    ans += temp;
                }else{
                    ans += " ";
                    ans += temp;
                }
                cnt = 0;
            }
            if(s[i] != ' ')
            temp += s[i];
            else
            temp.clear();

            i++;
        }
                if(cnt == j){
                    reverse(temp.begin() , temp.end());
                    ans += " ";
                    ans += temp;
                }else{
                    ans += " ";
                    ans += temp;
                }

                while(ans.back() == ' '){
                    ans.pop_back();
                }
        return ans;
    }
};