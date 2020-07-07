#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 100001
ll id[MAX], n, k;
void initialize(){
  for(ll i=0;i<MAX;i++){
    id[i] = i;
  }
}
ll root(ll x){
  while(id[x] != x){
    // id[x] = id[id[x]];
    x = id[x];
  }
  return x;
}
void union1(ll x, ll y){
  ll p = root(x);
  ll q = root(y);
  id[p] = id[q];
}
double minimum_distance(vector<ll> &x, vector<ll> &y) {  
  vector<double> result;
  ll index = 0, dist, x1, y1, cost, i, j;
  initialize();
  vector<pair<ll,pair<ll,ll> > > v; 
  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){      
      dist = (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]);
      v.push_back({dist,{i,j}}); 
      index++;
    }
  }
  sort(v.begin(),v.end());
  for(i=0;i<v.size();i++){
    x1 = v[i].second.first;
    y1 = v[i].second.second;
    cost = v[i].first;
    if(root(x1) != root(y1)){
      union1(x1, y1);
      result.push_back(cost);
    }
  }
  sort(result.rbegin(),result.rend());
  return sqrt(result[k-2]);
} 
int main() {
  cin >> n;
  vector<ll> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  cin>>k;
  cout << std::setprecision(10) << minimum_distance(x, y) << endl;
}