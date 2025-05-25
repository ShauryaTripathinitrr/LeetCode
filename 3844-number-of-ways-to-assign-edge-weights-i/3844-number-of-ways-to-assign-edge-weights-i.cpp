#define ll long long
class Solution {
    const int m=1000000007;
int binaryexp(int a,int b){
    if(b==0){
        return 1;
    }
    long long res=binaryexp(a,b/2);
    if(b&1){
        return ((a)%m*((res*res)%m))%m;
    }
    else{
        return ((res)%m*(res)%m)%m;
    }
}
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        
        unordered_map<int , vector<int>>mp;
        int mai = 0;
        for(auto & x : edges){
            mp[x[0] - 1].push_back(x[1] - 1);
            mp[x[1] - 1].push_back(x[0] - 1);
            mai = max(mai , max(x[0] - 1 , x[1] - 1));
        }

        vector<int>dist(mai + 1 , 1e9);

        queue<pair<int , int>>q;
        q.push({0 , 0});
        dist[0] = 0;
        while(!q.empty()){
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();

            for(auto & x : mp[node]){
                if(1 + steps < dist[x]){
                        dist[x] = 1 + steps;
                        q.push({x , dist[x]});
                    }
            }
        }
        int maxi = 0;
        for(auto & x : dist){
            maxi = max(maxi , x);
        }
        return binaryexp(2 , maxi - 1);
    }
};