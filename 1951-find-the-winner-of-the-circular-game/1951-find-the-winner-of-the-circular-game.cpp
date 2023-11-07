class Solution {
public:
 queue<int> q;
    int findTheWinner(int n, int k) {
        for(int i=1;i<=n;i++){
            q.push(i);
        }
        while(q.size()>1){
            int c =k;
            while(c>1){
                int x = q.front();
                q.pop();
                q.push(x);
                c--;
            }
            q.pop();
        }
        return q.front();
    }
};