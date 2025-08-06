class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n , vector<int>(m , 0));

        queue<pair<int , pair<int , int>>>q;
        //time , {row , col}

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2){
                    vis[i][j] = 2;
                    q.push({0 , {i , j}});
                }
            }
        }
        int maxi = 0;
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        while(!q.empty()){
            int row = q.front().second.first;
            int col = q.front().second.second;
            int tq = q.front().first;
            maxi = max(maxi , tq);
            q.pop();
            for(int x = 0 ; x < 4 ; x++){
                int dr = row + delrow[x];
                int dc = col + delcol[x];
                if(dr < n && dc < m && dr >= 0 && dc >= 0 && vis[dr][dc] != 2 && grid[dr][dc] == 1){
                    vis[dr][dc] = 2;
                    q.push({tq + 1 , { dr , dc }});
                }
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(vis[i][j] != 2 && grid[i][j]){
                    return -1;
                }
            }
        }
        return maxi;
    }
};