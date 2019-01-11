#include<bits/stdc++.h>
using namespace std;
#define ll long long int
// first approach is by sorting end point and it is the best 
// the second one rather comlex and not complete sorts by first one
bool cmp( const  pair<ll,ll> &a, const  pair<ll,ll> &b ) {
    return a.second < b.second ;
}
void optimal_polls(vector<pair<ll,ll> > &segments) {
  vector<ll> polls;
  sort(segments.begin(), segments.end(),cmp);
  // for(ll i=0;i<segments.size();i++){
  //   cout<<segments[i].first<<" "<<segments[i].second<<"\n";
  // }
  ll start = segments[0].first, end = segments[0].second, count = 0, marker = segments[0].second,flag = 0;

  for(ll i=1;i<segments.size();i++){
      if(segments[i].first <= marker){
        continue;
      }else{
        polls.push_back(marker);
        start = segments[i].first;
        end = segments[i].second;
        marker = segments[i].second;
        // if(i == segments.size() - 1)flag =1;
      }
    
  }
  polls.push_back(marker);
  cout << polls.size() << "\n";
  for (size_t i = 0; i < polls.size(); ++i) {
    cout << polls[i] << " ";
  }
  cout<<"\n";
}

// void optimal_polls(vector<pair<ll,ll> > &segments) {
//   vector<ll> polls;
//   sort(segments.begin(), segments.end());
//   // for(ll i=0;i<segments.size();i++){
//   //   cout<<segments[i].first<<" "<<segments[i].second<<"\n";
//   // }
//   ll start = segments[0].first, end = segments[0].second, count = 0, marker = segments[0].second,flag = 0;

//   for(ll i=1;i<segments.size();i++){
    
//     if(segments[i].first > marker){
//       // cout<<"hehe\n";
//       polls.push_back(marker);
//       start = segments[i].first;
//       end = segments[i].second;
//       marker = segments[i].second;
//       if(i == segments.size() -1)flag =1;
//       count++;
//     }else if(segments[i].second <= end){
//       // cout<<"lol\n";
//       end = segments[i].second;
//       marker = segments[i].second;  
//     }else{
//       // cout<<"kkkk\n";
//       // marker = end;
//       end = segments[i].second;
//     }    
//   }
//   if(flag == 0){
//     polls.push_back(marker);
//   }
//   // for (size_t i = 0; i < segments.size(); ++i) {
//   //   polls.push_back(segments[i].first);
//   //   polls.push_back(segments[i].second);
//   // }
//   cout << polls.size() << "\n";
//   for (size_t i = 0; i < polls.size(); ++i) {
//     cout << polls[i] << " ";
//   }
//   // cout<<"\n";
//   // return polls;
// }

int main(void) {
  ll n,x,y;
  cin >> n;
  vector< pair<ll,ll> > segments;
  for (size_t i = 0; i < n; ++i) {
    cin>> x >> y;
    segments.push_back(make_pair(x,y));
  }
  optimal_polls(segments);
}
