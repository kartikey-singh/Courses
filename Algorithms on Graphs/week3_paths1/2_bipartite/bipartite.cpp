#include <iostream>
#include <vector>
#include<queue>
using namespace std;
int n, m, x, y, color[100001], flag = 1, visited[100001];
vector<int> v;
void bfs(vector<vector<int> > &adj) {  
  queue<int> q;  
  int u = 0;
  q.push(u);
  color[u] = 0;
  while(!q.empty()){
    int u = q.front();
    visited[u] = true;
    q.pop();
    for(int i=0;i<adj[u].size();i++){
      int v = adj[u][i];      
      if(visited[v] == 0){
        q.push(v);        
        if(color[u] == 0)
          color[v] = 1;
        else 
          color[v] = 0;
      }else if(color[v] == color[u]){
        flag = 0;
        break;
      }
    }    
  }
}

int main() {  
  cin >> n >> m;
  vector<vector<int> > adj(n);  
  for (size_t i = 0; i < m; i++) {
    cin >> x >> y;
    adj[x - 1].push_back(y - 1);  
    adj[y - 1].push_back(x - 1);
  }  
  bfs(adj);  
  cout<<flag;
}
