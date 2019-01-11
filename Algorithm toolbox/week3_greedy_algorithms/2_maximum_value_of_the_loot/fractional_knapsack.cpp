#include<bits/stdc++.h>
using namespace std;
bool cmp( const  pair<double,int> &a, const  pair<double,int> &b ) {
    return a.first > b.first ;
}
double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  vector<pair<double,int> > p;
  for(int i=0;i<weights.size();i++){
    p.push_back( make_pair(values[i]/(double)weights[i] ,i) );
  }
  sort(p.begin(),p.end(),cmp);
  for(int i=0;i<weights.size();i++){
    if(weights[p[i].second] <= capacity){
      capacity -= weights[p[i].second];
      value += values[p[i].second];
    }else{
      value += (values[p[i].second]*(capacity))/(double)weights[p[i].second];
      capacity = 0;
      break;
    }
  }
  return value;
}
int main() {
  int n,x,y;
  int capacity;
  cin >> n >> capacity;
  vector<int> values;
  vector<int> weights;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    values.push_back(x);
    weights.push_back(y);
  }
  double optimal_value = get_optimal_value(capacity, weights, values);
  cout.precision(10);
  cout << optimal_value << endl;
  return 0;
}