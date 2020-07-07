#include <iostream>
#include <vector>
using namespace std;
int n, m, x, y, flag = 0, visited[10001], visit[10001];
vector<int> v;

void dfs(vector<vector<int> > &adjR, int u) {  
  visited[u] = true;
  // cout<<"I am in "<<u+1<<"---\n";
  for(int i =0;i<adjR[u].size();i++){
    if(!visited[adjR[u][i]]){
      // cout<<u+1<<" "<<adjR[u][i]+1<<"\n";
      dfs(adjR,adjR[u][i]);
    }
  }
  v.push_back(u);
  // cout<<u+1<<"@@@";
  // cout<<"Hola\n";
}

void dfsUtil(vector<vector<int> > &adj, int u, int cnt) {  
  visit[u] = cnt;
  for(int i =0;i<adj[u].size();i++){
    if(visit[adj[u][i]] == 0)
      dfsUtil(adj,adj[u][i], cnt);
  }  
}

int main() {  
  cin >> n >> m;
  vector<vector<int> > adj(n);
  vector<vector<int> > adjR(n);
  for (size_t i = 0; i < m; i++) {
    cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adjR[y - 1].push_back(x - 1);
  }
  // cout<<"------\n"  ;
  for(int i=0;i<n;i++){
    if(!visited[i]){
      dfs(adjR, i);   
    }
  }
  // for(int i=0;i<v.size();i++){
  //   cout<<v[i]<<" ";
  // }
  // cout<<"\n";
  int cnt = 1;
  for(int i=v.size()-1;i>=0;i--){
    if(visit[v[i]] == 0){      
      dfsUtil(adj,v[i],cnt);
      cnt++;
    }
  }
  // for(int i=0;i<n;i++){
  //   cout<<visit[i]<<" ";
  // }
  cout<<cnt-1;
}