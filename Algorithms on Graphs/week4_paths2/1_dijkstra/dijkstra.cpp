#include <iostream>
#include <vector>
#include<queue>
#define inf 1000001
using namespace std;
int n, m, x, y, dist[100001], visited[100001];

void path(vector<vector<int> > &adj, vector<vector<int> > &cost, int s) {  
  priority_queue <int, vector<int>, greater<int> > q;
  dist[s] = 0;  
  q.push(s);
  while(!q.empty()){
    int u = q.top();
    visited[u] = true;
    // if()
    q.pop();
    for(int i=0;i<adj[u].size();i++){
      int v = adj[u][i];      
      if(dist[v] > dist[u] + cost[u][i]){
        dist[v] = dist[u] + cost[u][i];
        q.push(v);
      }        
    }    
  }
}

int main(void){
  int n, m, x, y, w, s, t;
  cin >> n >> m;
  vector<vector<int> > adj(n);
  vector<vector<int> > cost(n);
  for(int i=0;i<n;i++){
    dist[i] = inf;
  }
  for(int i=0;i<m;i++){  
    cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  cin >> s >> t;
  s--, t--;
  path(adj, cost, s);
  if(dist[t] == inf)cout<<-1;
  else cout << dist[t];
}