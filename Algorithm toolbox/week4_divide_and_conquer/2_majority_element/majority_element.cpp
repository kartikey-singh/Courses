#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll get_majority_element(vector<ll> &a, ll left, ll right) {
  // cout<<left<<" "<<right<<"\n";
  if (left == right) return -1;
  // cout<<"YOLO\n";
  if (left + 1 == right) return a[left];
  //write your code here
  ll mid = left + (right-left)/2,countl =0,countr=0;
  ll l = get_majority_element(a,left,mid);
  ll r = get_majority_element(a,mid,right);
  for(ll i = left;i < right;i++){
    if(a[i] == l)countl++;
    if(a[i] == r)countr++;  
  }
  // for(ll i = mid;i < right;i++){
    
  // }
  // cout<<l<<" "<<r<<" "<<countl<<" "<<countr<<"\n";
  if(countl > (right - left )/2){
    // cout<<"chopla\n";
    return l;
  }
  else if(countr > (right - left )/2){
    // cout<<"loloa\n";
    return r;
  }
  else {
    // cout<<"bhopla\n";
    return -1;
  }
}
// ll fun(vector<ll> &v) {
//   if(v.size() == 1)return 1;
//   sort(v.begin(), v.end());
//   ll start = v[0],count=1;
//   // for(ll i=0;i<v.size();i++)cout<<v[i]<<" ";
//   // cout<<"\n"; 
//   for(ll i=1;i<v.size();i++){
//     // cout<<v[i]<<" ";
//     if(v[i] == start)count++;
//     else{
//       if(count > (v.size()/2) ){
//         return 1;
//       }
//       count=0;
//       start = v[i];
//     }
//   }
//   return 0;
// }
int main(void) {
  ll n,x;
  cin >> n;
  vector<ll> a;
  for (size_t i = 0; i < n; ++i) {
    cin >> x;
    a.push_back(x);
  }
  cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
  // cout<<fun(a)<<"\n";
}
