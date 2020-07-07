#include <iostream>
#include <vector>
using namespace std;
int x, y, n, m, flag = 0, visited[1001];

void reach(vector<vector<int> > &adj, int u) {
  //write your code here  
  if(!visited[u]){
    visited[u] = true;
  }else return;
  if(u == y){
    flag = 1;
    return;
  }

  for(int i=0;i<adj[u].size();i++){
    reach(adj, adj[u][i]);
  }  
  return;
}

int main() {
  cin >> n >> m;
  vector<vector<int> > adj(n);
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }  
  cin >> x >> y;
  x--, y--;
  // cout<<x<< " "<<y;
  reach(adj, x);
  cout << flag;;
}
