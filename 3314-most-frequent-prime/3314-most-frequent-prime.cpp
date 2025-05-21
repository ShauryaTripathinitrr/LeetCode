class Solution {
    map<string , int>mp;
    int n , m;
    vector<vector<int>>vis;
    bool isPrime(int n) {
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}
    void solver(int row , int col ,vector<vector<int>>& mat) {
        //traverse all dirn as far as you can and you cannot change the direction in between.

        int r = row;
        int c = col;

        string up = "";

        while(r >= 0){//up
            char ch = (mat[r--][c] + '0');
            up.push_back(ch);
            mp[up]++;
        }

        r = row;
        up = "";

        while(r < n){//down
            char ch = (mat[r++][c] + '0');
            up.push_back(ch);
            mp[up]++;
        }

        r = row;
        up = "";
        while(c >= 0){//left
            char ch = (mat[r][c--] + '0');
            up.push_back(ch);
            mp[up]++;
        }

        c = col;
        up = "";
        while(c < m){//right
            char ch = (mat[r][c++] + '0');
            up.push_back(ch);
            mp[up]++;
        }

        c = col;
        up = "";
        while(c < m && r >= 0){//north east
            char ch = (mat[r--][c++] + '0');
            up.push_back(ch);
            mp[up]++;
        }

        r = row;
        c = col;
        up = "";
        while(c >= 0 && r >= 0){//north west
            char ch = (mat[r--][c--] + '0');
            up.push_back(ch);
            mp[up]++;
        }

        r = row;
        c = col;
        up = "";
        while(c >= 0 && r < n){//south west
            char ch = (mat[r++][c--] + '0');
            up.push_back(ch);
            mp[up]++;
        }

        r = row;
        c = col;
        up = "";
        while(c < m && r < n){//south east
            char ch = (mat[r++][c++] + '0');
            up.push_back(ch);
            mp[up]++;
        }
        string s = to_string(mat[row][col]);
        mp[s] -= 7;

        return;
    }
public:
    int mostFrequentPrime(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();
        vis.resize(n , vector<int>(m , 0));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                solver(i , j , mat);
            }
        }

        int ans = -1;
        int maxfreq = 0;

        for(auto & x : mp){
            if(x.first.length() == 0){
                continue;
            }
            int num = stoi(x.first);

            if(isPrime(num) && x.first.length() > 1){
                cout << num << " " << x.second << endl;
                if(x.second >= maxfreq){
                    if(maxfreq < x.second){
                        ans = num;
                    }else if(maxfreq == x.second){
                        if(num > ans){
                            ans = num;
                        }
                    }
                    maxfreq = x.second;
                }
            }
        }
        cout << maxfreq << endl;
        return ans;
    }
};