#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// vector<ll> fast_count_segments(vector<ll> starts, vector<ll> ends, vector<ll> polls) {
//   vector<ll> cnt(polls.size());
//   //write your code here
//   return cnt;
// }

// vector<ll> naive_count_segments(vector<ll> starts, vector<ll> ends, vector<ll> polls) {
//   vector<ll> cnt(polls.size());
//   for (size_t i = 0; i < polls.size(); i++) {
//     for (size_t j = 0; j < starts.size(); j++) {
//       cnt[i] += starts[j] <= polls[i] && polls[i] <= ends[j];
//     }
//   }
//   return cnt;
// }
//  It is a nice linear algo wher all the values ae sorted but their meanings are alos stored and using count we figure out what is asked
// Use 0,1,2 judicously as if end point of segment and asked are same you want asked befor end points so put it = 1;
int main(void) {
  ll n, m,x,y;
  cin >> n >> m;
  // vector<ll> starts(n), ends(n);
  map<ll,ll> m1;
  vector<pair<ll,ll> > v;
  for (size_t i = 0; i < n; i++) {
    cin >> x>> y;
    v.push_back(make_pair(x,0));
    v.push_back(make_pair(y,2));
  }
  vector<ll> polls;
  for (size_t i = 0; i < m; i++) {
    cin >> x;
    polls.push_back(x);
    v.push_back(make_pair(x,1)); 
  }
  //use fast_count_segments
  // sort(starts.begin(), starts.end());
  // sort(ends.begin(), ends.end());
  sort(v.begin(), v.end());
  ll count = 0;
  for(size_t i = 0;i < v.size();i++){
    if(v[i].second == 0)count++;
    else if(v[i].second == 1)m1[v[i].first] = count;
    else count--;
  }
  // vector<ll> cnt = naive_count_segments(starts, ends, polls);
  for (size_t i = 0; i < polls.size(); i++) {
    cout << m1[polls[i] ] << ' ';
  }
}
