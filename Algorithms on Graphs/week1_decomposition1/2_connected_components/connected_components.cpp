#include <iostream>
#include <vector>
using namespace std;
int n, m, x, y, visited[1001];
void dfs(vector<vector<int> > &adj, int u) {  
  if(!visited[u]){
    visited[u] = true;
  }else return;  
  
  for(int i=0;i<adj[u].size();i++){
    dfs(adj, adj[u][i]);
  }  
  
  return;  
}

int main() {  
  cin >> n >> m;
  vector<vector<int> > adj(n);
  for (size_t i = 0; i < m; i++) {
    cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int count = 0;
  for(int i=0;i<n;i++){
    if(!visited[i]){
      dfs(adj, i);
      count++;
    }
  }
  cout << count;
}
