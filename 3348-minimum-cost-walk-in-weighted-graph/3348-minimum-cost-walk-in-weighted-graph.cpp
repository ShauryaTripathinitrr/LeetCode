class DisjointSet{
    public:
    vector<int>rank, parent, size;
    DisjointSet(int n){
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUParent(u); 
        int ulp_v = findUParent(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUParent(u); 
        int ulp_v = findUParent(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
};
class Solution {
private:
void bfs(int node , int &a , vector<vector<pair<int,int>>> &adj , vector<int>& vis){
    queue<int>q;
    q.push(node);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(!vis[u]){
            vis[u] = 1;
            for(auto it : adj[u]){
                if(!vis[it.first]){
                    a &= it.second;
                    q.push(it.first);
                }
            }
        }
    }
}
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<vector<pair<int,int>>>adj(n);
        vector<int>ans;
        for(auto it : edges){
            auto u = it[0];
            auto v = it[1];
            auto wt = it[2];

            adj[u].push_back({v , wt});
            adj[v].push_back({u , wt});
        }

        DisjointSet ds(n);
        vector<int>vis(n , 0);
        for(auto &i : edges){
            if(ds.parent[i[0]] != ds.parent[i[1]]){
                ds.unionBySize(i[0],i[1]);
            }
        }
       // vector<int>vis(n , 0);
        map<int,int>mp;
        for(int i = 0 ; i < n ;i++){

            if(!vis[i]){
                int anding = INT_MAX;
                bfs(i , anding , adj , vis);
                int j = ds.findUParent(i);
                mp[j] = anding;
            }
        }
        for(auto it : query){
            int u = it[0];
            int v = it[1];

            if(ds.findUParent(u) != ds.findUParent(v)){
                ans.push_back(-1);
            }else{
                int k = ds.findUParent(u);
                ans.push_back(mp[k]);
            }
        }
        return ans;
    }
};