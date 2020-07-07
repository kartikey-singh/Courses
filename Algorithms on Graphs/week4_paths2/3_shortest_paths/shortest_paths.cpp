#include <iostream>
#include <vector>
#include<queue>
#define inf 10000000001
using namespace std;
long long int n, m, x, y, dist[100001], visited[100001], ans[100001];
void bfs(vector<vector<long long int> >&ad,long long int u) {  
  queue<long long int> q;  
  q.push(u);  
  while(!q.empty()){
    int u = q.front();
    q.pop();
    visited[u] = true;
    ans[u] = -1;
    for(long long int i=0;i<ad[u].size();i++){
      long long int v = ad[u][i];            
      if(!visited[v])
        q.push(v);              
    }    
  }
}
void path(vector<pair<long long int,long long int> > &adj, vector<long long int> &cost, int s, vector<vector<long long int> >& ad) {  
  long long int i, j, u, v;  
  dist[s] = 0;  
  for(i=0;i<n-1;i++){
    for(j=0;j<m;j++){
      u = adj[j].first;
      v = adj[j].second;      
      if(dist[u] != inf && dist[v] > cost[j] + dist[u]){
        dist[v] = dist[u] + cost[j];        
      }
    }
  }    
  for(i=0;i<m;i++){
    u = adj[i].first;
    v = adj[i].second;        
    if(dist[u] != inf && dist[v] > dist[u] + cost[i]){              
      bfs(ad, v);
    }      
  }  
  for(i=0;i<n;i++){
    if(dist[i] == inf)cout<<"*";
    else if(ans[i] == -1)cout<<"-";
    else cout<<dist[i];
    cout<<"\n";
  }
}

int main(void){
  long long int x, y, w;
  cin >> n >> m;
  vector<pair<long long int,long long int> > adj;
  vector<long long int> cost;
  vector<vector<long long int> > ad(n);
  for(int i=0;i<n;i++){
    dist[i] = inf;
  }
  for(long long int i=0;i<m;i++){  
    cin >> x >> y >> w;
    adj.push_back({x-1,y-1});    
    ad[x-1].push_back(y-1);
    cost.push_back(w);
  }  
  cin>>x;
  x--;
  path(adj, cost, x, ad);  
}