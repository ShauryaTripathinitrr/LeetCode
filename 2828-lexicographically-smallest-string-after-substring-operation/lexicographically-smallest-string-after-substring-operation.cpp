class Solution {
public:
    string smallestString(string s) {
        int ops = 0;
        int n = s.length();
        int start = -1;
        int end = -1;
        bool check = true;
        for(int i = 0 ; i < n ; i++){
            if(s[i] != 'a'){
                if(check){
                    check = false;
                    start = i;
                }
            }else{
                if(check == false){
                    end = i - 1;
                    break;
                }
            }
        }
        if(start == -1){
            start = n - 1;
        }
        if(start != -1 && end == -1){
            end = n - 1;
        }
        string ans = "";
        for(int i = 0 ; i < n ; i++){
            if(i < start || i > end){
                ans.push_back(s[i]);
            }else{
                int ascii = (s[i] - 'a');
                if(ascii == 0){
                    ans.push_back('z');
                }else{
                    ans.push_back((char)( (ascii - 1) + 'a'));
                }
            }
        }
        return ans;
    }
};