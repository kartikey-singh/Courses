#include <iostream>
#include <vector>
#include<queue>
using namespace std;
int n, m, x, y, visited[100001], indegree[100001];
vector<int> v;
void bfs(vector<vector<int> > &adj) {  
  for(int i=0;i<n;i++){
    for(int j=0;j<adj[i].size();j++){
      indegree[adj[i][j]]++;
    }
  }
  queue<int> q;
  for(int i=0;i<n;i++){
    // cout<<indegree[i]<<" ";
    if(indegree[i] == 0){
      q.push(i);
      // cout<<i<<" ";
    }
  }
  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int i=0;i<adj[u].size();i++){
      int v = adj[u][i];
      indegree[v]--;
      if(indegree[v] == 0)q.push(v);
    }
    v.push_back(u);
  }
}

int main() {  
  cin >> n >> m;
  vector<vector<int> > adj(n);
  for (size_t i = 0; i < m; i++) {
    cin >> x >> y;
    adj[x - 1].push_back(y - 1);  
  }
  bfs(adj);
  for(int i=0;i<v.size();i++)
    cout<<v[i]+1<<" ";
}
