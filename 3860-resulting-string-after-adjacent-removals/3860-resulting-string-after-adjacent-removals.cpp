class Solution {
public:
    string resultingString(string s) {
        string ans = "";

        stack<int>st;

        for(auto & x : s){
            if(st.empty()){
                st.push(x - 'a');
            }else{
                bool c = false;
                if((abs(st.top() - (x - 'a')) == 1 || abs(st.top()- (x - 'a')) == 25)){
                    c = 1;
                    st.pop();
                }
                if(!c)
                st.push(x - 'a');
            }
        }
        while(!st.empty()){
            ans.push_back((char)(st.top() + 'a'));
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};