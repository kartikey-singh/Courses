#include<bits/stdc++.h>
#define dd double
using namespace std;
bool cmp(pair<dd,dd> &a,pair<dd,dd> &b){
  return a.second < b.second;
}

double dist(pair<dd,dd> a,pair<dd,dd> b){
  double x = a.first-b.first, y = a.second - b.second;
  return sqrt(x*x + y*y);
}

double hybrid(vector<pair<dd,dd> > y,pair<dd,dd> mid,double d){
  vector<pair<dd,dd> > yy;
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

double minimal_distance(vector<pair<dd,dd> > xs, vector<pair<dd,dd> > ys,long long int left,long long int right) {
  if(right - left< 2)return -1;
  if(right - left <= 3){
    double min = DBL_MAX; 
    for(long long int i=left;i<right;i++){
      for(long long int j = i+1;j<right;j++){
        double dis = dist(xs[i],xs[j]);
        if(dis < min){
          min = dis;
        }
      }
    }
    return min;
  }
  
  long long int mid = left + (right - left)/2;
  vector<pair<dd,dd> >  yl;
  vector<pair<dd,dd> >  yr;
  for(long long int i = 0;i < ys.size();i++){  
    if(ys[i].first < xs[mid].first)yl.push_back(ys[i]);
    else yr.push_back(ys[i]);
  }
  double dl = minimal_distance(xs,yl,left,mid);
  double dr = minimal_distance(xs,yr,mid,right);
  double d = min(dl,dr);
  double dh = hybrid(ys,xs[mid],d);
  return min(d,dh);
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);   
  cout.tie(NULL);
  dd n,x,y;
  cin >> n;
  vector<pair<dd,dd> > xs;
  vector<pair<dd,dd> > ys;
  for (size_t i = 0; i < n; i++) {
    cin >> x >> y;
    xs.push_back(make_pair(x,y));
    ys.push_back(make_pair(x,y));
  }
  sort(xs.begin(), xs.end());
  sort(ys.begin(), ys.end(), cmp);
  cout << fixed;
  cout << setprecision(9) << minimal_distance(xs,ys,0,xs.size()) << "\n";
}
