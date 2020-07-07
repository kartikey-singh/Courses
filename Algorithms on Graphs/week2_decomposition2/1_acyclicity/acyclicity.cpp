#include <iostream>
#include <vector>
using namespace std;
int n, m, x, y, flag = 0, color[1001];
void dfs(vector<vector<int> > &adj, int u) {  
  color[u] = 1;  
  for(int i=0;i<adj[u].size();i++){
    if(color[adj[u][i]] == 0)
      dfs(adj, adj[u][i]);
    if(color[adj[u][i]] == 1){
      // cout<<i<<" ";
      flag = 1;
      return;
    }
  }  
  color[u] = 2;
  return;  
}

int main() {  
  cin >> n >> m;
  vector<vector<int> > adj(n);
  for (size_t i = 0; i < m; i++) {
    cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }  
  for(int i=0;i<n;i++){
    if(color[i] == 0){
      dfs(adj, i);            
    }
  }
  cout << flag;
}
