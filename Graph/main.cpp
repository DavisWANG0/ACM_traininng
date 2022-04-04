#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
void SPFA(int n, int s, vector<vector<pair<int, int>>>& g) {
    int * dis = new int[n];
    bool * vis = new bool[n];
    memset(dis, 0x3f, sizeof(int)*n);
    memset(vis, false, sizeof(bool)*n);
    queue<int> q;
    q.push(s);
    vis[s] = true;
    dis[s] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        vis[u] = false;
        for(int i = 0; i < g[u].size(); i++){
            int v = g[u][i].first;
            int w = g[u][i].second;
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        cout << dis[i] << " ";
    }
}

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<vector<pair<int, int>>> g(n);
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    SPFA(n, s, g);
    return 0;
}
