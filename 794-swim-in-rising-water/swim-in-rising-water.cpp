class Disjoint_set{
    vector<int>parent,rank,size;
public:
    Disjoint_set(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,1);
        for(int i = 0; i <= n; i++) parent[i] = i;
    }
    int findParent(int node){
        if(parent[node]==node)
        return node;
        else
        return parent[node]=findParent(parent[node]);
    }
    void UnionBySize(int u,int v){
        int pu=findParent(u);
        int pv=findParent(v);
        if(pu==pv)
            return;
        
           if(size[pu]>size[pv]){
				parent[pv]=pu;
				size[pu]+=size[pv];
			}
			else
			parent[pu]=pv;
			size[pv]+=size[pu];
        }
    
};
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        Disjoint_set ds(n * n);
        vector<tuple<int , int , int>>helper;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                helper.push_back({grid[i][j] , i , j});
            }
        }
        vector<bool>vis(n * n , false);

        sort(helper.begin() , helper.end());
        vector<int>delrow = {0 , 0 , 1 , -1};
        vector<int>delcol = {-1 , 1 , 0 , 0};

        for(auto &[height , row , col] : helper){
            int i1 = n * row + col;
            vis[i1] = true;
            for(int i = 0 ; i < 4 ; i++){
                int nr = row + delrow[i];
                int nc = col + delcol[i];

                if(nr >= 0 && nc >= 0 && nr < n && nc < n && vis[nr * n + nc]){
                    int i2 = n * nr + nc;
                    ds.UnionBySize(i1 , i2);
                }
            }
            if(ds.findParent(0) == ds.findParent(n * n - 1)){
            return height;
            }
        }
        return -1;
    }
};