class Solution {
public:
    string countAndSay(int n) {
        if(n == 1){
            return "1";
        }
        string ans ="";
        string temp ="1";
         //solver(1 , "1" , n , ans);
          for(int i = 1 ; i < n ; i++){
             string jam = "";
             int freq = 0;
             char ch = temp[0];
            for(int i = 0 ; i < (temp.length()) ; i++){
            if(ch == temp[i]){
              freq++;
              }else{
              jam.push_back((char)(freq + '0'));
              jam.push_back(ch);
              ch = temp[i];
              freq = 1;
            }
        }
         
          jam.push_back((char)(freq + '0'));
          jam.push_back(ch);
            temp = jam;
          }
        return temp;
    }
};