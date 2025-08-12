class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>dist(n , vector<int>(n , 1e9));
        if(grid[0][0] != 0){
            return -1;
        }
        dist[0][0] = 1;
        //pair<int , pair<int , int>>
        priority_queue<pair<int , pair<int , int>> , vector<pair<int , pair<int , int>>> , greater<pair<int , pair<int , int>>>>pq;
        pq.push({1 , {0 , 0}});

        while(!pq.empty()){
            int d = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            for(int row = -1 ; row<= 1 ; row++){
                for(int col = -1 ; col <= 1 ; col++){
                    int a = i + row;
                    int b = j + col;
                    if(a >= 0 && b >= 0 && a < n && b < n && grid[a][b] == 0 && d + 1 < dist[a][b]){
                        dist[a][b] = 1 + d;
                        pq.push({dist[a][b] , {a , b}});
                    }
                }
            }
        }
    return (dist[n - 1][n - 1] == 1e9 ? -1 : dist[n - 1][n - 1]);
    }
};