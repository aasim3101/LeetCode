#define ll long long
class Solution {
public:
    int mod = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<ll> dist(n,LONG_MAX),ways(n);
        priority_queue<pair<ll,ll>,vector<pair<ll,ll> >,greater<>> pq;
        vector<vector<pair<ll,ll> > > adj(n);
        for(auto vec : roads){
            int u=vec[0];
            int v=vec[1];
            int wt=vec[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        pq.push({0,0});
        dist[0]=0;
        ways[0]=1;
        while(!pq.empty()){
            ll d=pq.top().first;
            ll u=pq.top().second;
            pq.pop();
            if(d > dist[u]) continue;
            for(auto pr : adj[u]){
                ll v=pr.first,w=pr.second;
                if(d + w < dist[v]){
                    dist[v]=(d + w);
                    pq.push({dist[v], v});
                    ways[v]=ways[u];
                }
                else if(d + w == dist[v]){
                    ways[v]=(ways[u] + ways[v])%mod;
                }
            }
        }
        return ways[n-1];
    }
};