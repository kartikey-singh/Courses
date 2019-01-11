#include<bits/stdc++.h>
#define ll long long int
using namespace std;


ll binary_search(const vector<ll> &a, ll x,ll start ,ll end) {
  if(end >= start){ // Important step if element not in array 
    ll mid = start + (end - start)/2;
    if(a[mid] == x)return mid;
    else if(a[mid] > x )return binary_search(a,x,start,mid -1);
    else return binary_search(a,x,mid+1,end);  
  }
  return -1;
}

// ll linear_search(const vector<ll> &a, ll x) {
//   for (size_t i = 0; i < a.size(); ++i) {
//     if (a[i] == x) return i;
//   }
//   return -1;
// }

int main(void) {
  ll n,x;
  cin >> n;
  vector<ll> a;
  for (size_t i = 0; i < n; i++) {
    cin >> x;
    a.push_back(x);
  }
  ll m;
  cin >> m;
  vector<ll> b;
  for (ll i = 0; i < m; ++i) {
    cin >> x;
    b.push_back(x);
  }
  for (ll i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    cout << binary_search(a, b[i],0,a.size()-1) << ' ';
  }
}
