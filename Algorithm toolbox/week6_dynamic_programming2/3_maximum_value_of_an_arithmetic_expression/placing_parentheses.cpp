#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll eval1(ll a, ll b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}
ll max1(ll a,ll b){
  return (a>b)?a:b;
}
ll min1(ll a,ll b){
  return (a>b)?b:a;
}
ll get_maximum_value(const string &s) {
  ll n = s.length();
  vector <ll> d;
  vector <char> op;
  for(ll  i =0;i<n;i++){
    if(i%2 == 0){
      d.push_back(s[i] - 48);
    }else{
      op.push_back(s[i]);
    }
  }
  ll N = d.size();
  ll m[N][N],M[N][N];
  for(ll i=0;i<N;i++){
      m[i][i]=d[i];
      M[i][i]=d[i];
  }
  for(ll s1 = 0;s1 < N;s1++){
    for(ll i = 0;i < N - s1 - 1;i++ ){
      // Done to go through all possible pairs of j - i == s1 + 1
      ll j = i + s1 + 1,min=LONG_MAX,max =LONG_MIN;
      for(ll k = i;k<j;k++){
        ll a =  eval1(M[i][k],M[k+1][j],op[k]);
        ll b =  eval1(M[i][k],m[k+1][j],op[k]);
        ll c =  eval1(m[i][k],m[k+1][j],op[k]);
        ll d =  eval1(m[i][k],M[k+1][j],op[k]);
        min = min1(min,min1(a,min1(b,min1(c,d))));
        max = max1(max,max1(a,max1(b,max1(c,d))));
      }
      m[i][j] = min;
      M[i][j] = max;
    }
  }
  return M[0][N-1];  
}

int main(void) {
  string s;
  cin >> s;
  cout << get_maximum_value(s) << '\n';
}
