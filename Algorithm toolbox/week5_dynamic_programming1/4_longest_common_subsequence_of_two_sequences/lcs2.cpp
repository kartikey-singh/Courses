#include<bits/stdc++.h>
#define ll long long int
#define mp make_pair
using namespace std;
ll max1(ll a,ll b){
  return (a>b)?a:b;
}
ll lcs2(vector<ll> &a, vector<ll> &b) {
  ll m = a.size(),n=b.size(),dp[m+1][n+1];
  for(ll i=0;i<m+1;i++){
    for(ll j=0;j<n+1;j++){
      if(i == 0 || j == 0)dp[i][j]=0;
      else if(a[i-1] == b[j-1])dp[i][j] = 1+dp[i-1][j-1];
      else{
        dp[i][j] = max1(dp[i-1][j],dp[i][j-1]);
      }  
    }
  }
  return dp[m][n];
}

int main() {
  ll n,m;
  cin >> n;
  vector<ll> a(n);
  for (ll i = 0; i < n; i++)cin >> a[i];
  cin >> m;
  vector<ll> b(m);
  for (ll i = 0; i < m; i++)cin >> b[i];
  cout << lcs2(a, b) << endl;
}
