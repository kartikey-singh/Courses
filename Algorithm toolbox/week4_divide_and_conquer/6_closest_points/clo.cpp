#include<bits/stdc++.h>
#define ll double
using namespace std;
// Compare function to sort (x,y) accorting to Y
bool cmp(pair<ll,ll> &a,pair<ll,ll> &b){
  return a.second < b.second;
}
// Function to calculate Euclidean Distance
double dist(pair<ll,ll> a,pair<ll,ll> b){
  double x = a.first-b.first, y = a.second - b.second;
  return sqrt(x*x + y*y);
}
// Function to calculate distances between points in the region d*2d around partition line
double hybrid(vector<pair<ll,ll> > y,pair<ll,ll> mid,double d){
  vector<pair<ll,ll> > yy;
  for(long long int i = 0;i<y.size();i++){
    if(abs(y[i].first - mid.first) <= d){
      yy.push_back(y[i]);
    }
  }
  long long int len = yy.size();
  for(long long int i=0;i < len-1;i++){
    for(long long int j=i+1;j < len;j++){
      if(abs( yy[i].second - yy[j].second ) <= d){
        double dis = dist(yy[i],yy[j]);
        if(dis < d){
          d = dis;
        }
      }
    }
  } 
  return d;
}
// Main Function
double minimal_distance(vector<pair<ll,ll> > xs, vector<pair<ll,ll> > ys) {
  if(xs.size()< 2)return -1;
  if(xs.size() <= 3){
    double min = DBL_MAX; 
    for(ll i=0;i<xs.size()-1;i++){
      for(ll j = i+1;j<xs.size();j++){
        double dis = dist(xs[i],xs[j]);
        if(dis < min){
          min = dis;
        }
      }
    }
    return min;
  }
  
  long long int mid = xs.size()/2;
  vector<pair<ll,ll> >  yl;
  vector<pair<ll,ll> >  yr;
  vector<pair<ll,ll> >  xl;
  vector<pair<ll,ll> >  xr;
  
  for(long long int i = 0;i < xs.size();i++){
    if(i<mid)xl.push_back(xs[i]);
    else xr.push_back(xs[i]);
  }
  for(long long int i = 0;i < ys.size();i++){  
    if(ys[i].first < xs[mid].first)yl.push_back(ys[i]);
    else yr.push_back(ys[i]);
  }
  double dl = minimal_distance(xl,yl);
  double dr = minimal_distance(xr,yr);
  double d = min(dl,dr);
  double dh = hybrid(ys,xs[mid],d);
  return min(d,dh);
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);   
  cout.tie(NULL);
  ll n,x,y;
  cin >> n;
  vector<pair<ll,ll> > xs;
  vector<pair<ll,ll> > ys;
  for (size_t i = 0; i < n; i++) {
    cin >> x >> y;
    xs.push_back(make_pair(x,y));
    ys.push_back(make_pair(x,y));
  }
  sort(xs.begin(), xs.end());
  sort(ys.begin(), ys.end(), cmp);
  cout << fixed;
  cout << setprecision(9) << minimal_distance(xs,ys)<< "\n";
}
