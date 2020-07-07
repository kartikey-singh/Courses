#include <iostream>
#include <vector>
#include<queue>
#define inf 1000001
using namespace std;
int n, m, x, y, dist[100001], visited[100001], flag=0;

void path(vector<pair<int,int> > &adj, vector<int> &cost, int s) {  
  int i, j, u, v;  
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
  for(j=0;j<m;j++){
    u = adj[j].first;
    v = adj[j].second;
    if(dist[u] != inf && dist[v] > dist[u] + cost[j]){
      flag = 1;
      break;
    }
  }
}

int main(void){
  int x, y, w;
  cin >> n >> m;
  vector<pair<int,int> > adj;
  vector<int> cost;
  for(int i=0;i<n;i++){
    dist[i] = inf;
  }
  for(int i=0;i<m;i++){  
    cin >> x >> y >> w;
    adj.push_back({x-1,y-1});
    cost.push_back(w);
  }  
  for(int i=0;i<n;i++){
    if(dist[i] == inf){
      path(adj, cost, i);    
    }
  }
  
  cout<<flag;
}