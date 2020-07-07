#include <iostream>
#include <vector>
#include<queue>
using namespace std;
int n, m, x, y, dist[100001];
vector<int> v;
void bfs(vector<vector<int> > &adj, int u, int y) {  
  queue<int> q;  
  q.push(u);
  dist[u] = 0;
  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int i=0;i<adj[u].size();i++){
      int v = adj[u][i];      
      if(dist[v] == -1){
        q.push(v);
        dist[v] = dist[u] + 1;
      }
      if(v == y)break;
    }    
  }
}

int main() {  
  cin >> n >> m;
  vector<vector<int> > adj(n);
  for(int i = 0;i<n;i++)dist[i] = -1;
  for (size_t i = 0; i < m; i++) {
    cin >> x >> y;
    adj[x - 1].push_back(y - 1);  
    adj[y - 1].push_back(x - 1);
  }
  cin>>x>>y;
  x--;y--;
  bfs(adj,x,y);  
  cout<<dist[y];
}
