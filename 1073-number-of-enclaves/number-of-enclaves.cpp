class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n , vector<int>(m , 0));
        queue<pair<int , int>>q;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1 && (i == 0 || i == n - 1 || j == 0 || j == m - 1)){
                    q.push({i , j});
                    vis[i][j] = 1;
                }
            }
        }
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int a = 0 ; a < 4 ; a++){
                int dr = row + delrow[a];
                int dc = col + delcol[a];
                if(dr >= 0 && dc >= 0 && dr < n && dc < m && grid[dr][dc] == 1 && !vis[dr][dc]){
                    vis[dr][dc] = 1;
                    q.push({dr , dc});
                }
            }
        }
        int ans = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(!vis[i][j] && grid[i][j]){
                    ans++;
                }
            }
        }
        return ans;
    }
};