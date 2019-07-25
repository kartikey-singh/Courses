#include<bits/stdc++.h>
#define ll long long int
using namespace std;
// simple quicksort
ll partition2(vector<ll> &a, ll l, ll r) {
  ll x = a[l];
  ll j = l;
  for (ll i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

// in 3 way partttion you do <x ==x >x partitions that is djikstra 3 way partitioning
// best method esay to learn
vector<ll> partition31(vector<ll> &a, ll l, ll r) {
  vector<ll> v;
  v.push_back(0);
  v.push_back(0);
  ll x = a[l],gt = r,lt = l;
  for(ll i = l +1;i<=r;i++){
    if(a[i]< x){
      swap(a[lt],a[i]);  
      lt++;
    }else if(a[i] > x){
      swap(a[gt],a[i]);
      gt--;
      i--;
    }else{
      continue;
    }

    if(i>gt)break;
  }
  lt--;gt++;
  v[0]=lt;
  v[1]=gt;
  return v;
}  

// below one is dual pivot partitioning
vector<ll> partition32(vector<ll> &a, ll l, ll r) {
  vector<ll> v;
  v.push_back(0);
  v.push_back(0);
  if(a[l] > a[r])swap(a[l],a[r]);
  ll x = a[l], y = a[r],lt = l+1, gt = r -1;
  for(ll i=l+1;i<=r;i++){
    if(i > gt)break;
    if(a[i] < x){
      swap(a[i],a[lt]);
      lt++;
    }else if(a[i] > y){
      swap(a[i],a[gt]);
      gt--;
      i--;
    }
  }
  lt--;gt++;
  swap(a[lt],a[l]);
  swap(a[gt],a[r]);
  v[0] = lt;
  v[1] = gt; 
  return v;
}

vector<ll> partition33(vector<ll> &a, ll l, ll r) {
  vector<ll> v;
  v.push_back(0);
  v.push_back(0);
  if(a[l] > a[r])swap(a[l],a[r]);
  ll x = a[l], y = a[r], j = l, q;
  for (ll i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  v[0] = j;
  swap(a[j+1],a[r]);
  q = j+1;
  for (ll i = j + 1; i <= r; i++) {
    if (a[i] <= y) {
      q++;
      swap(a[i], a[q]);
    }
  }
  swap(a[r], a[q]);
  v[1] = q;
  return v;
}

void randomized_quick_sort(vector<ll> &a, ll l, ll r) {
  if (l >= r) {
    return;
  }

  ll k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  // vector<ll> v= partition33(a, l, r);

  // randomized_quick_sort(a, l, v[0]-1);
  // randomized_quick_sort(a, v[0]+1, v[1]-1);
  // randomized_quick_sort(a, v[1]+1, r);  

  // for dual pivot one
  
  // vector<ll> v= partition32(a, l, r);
  // randomized_quick_sort(a, l, v[0]-1);
  // randomized_quick_sort(a, v[0]+1, v[1]-1);
  // randomized_quick_sort(a, v[1]+1, r);  

  //for djikstra one

  vector<ll> v= partition31(a, l, r);
  randomized_quick_sort(a, l, v[0]);
  randomized_quick_sort(a, v[1], r);
}

int main(void) {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    cout << a[i] << ' ';
  }
}
