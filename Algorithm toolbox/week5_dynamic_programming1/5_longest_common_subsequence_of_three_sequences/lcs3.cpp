#include<bits/stdc++.h>
#define ll long long int
#define mp make_pair
using namespace std;
ll max1(ll a,ll b){
  return (a>b)?a:b;
}
ll lcs3(vector<ll> &a, vector<ll> &b, vector<ll> &c) {
  ll m=a.size(),n=b.size(),o=c.size();
  ll dp[m+1][n+1][o+1];
  for(ll i=0;i<m+1;i++){
    for(ll j=0;j<n+1;j++){
      for(ll k=0;k<o+1;k++){
        if(i == 0 || j == 0 || k ==0)dp[i][j][k]=0;
        else if(a[i-1] == b[j-1] && c[k-1] == b[j-1])dp[i][j][k] = 1+dp[i-1][j-1][k-1];
        else{
          dp[i][j][k] = max1(dp[i-1][j][k],max1(dp[i][j-1][k],dp[i][j][k-1]));
        }  
      }
    }
  }
  return dp[m][n][o];
}

int main(void) {
  ll an,bn,cn;
  cin >> an;
  vector<ll> a(an);
  for (ll i = 0; i < an; i++) {
    cin >> a[i];
  }
  cin >> bn;
  vector<ll> b(bn);
  for (ll i = 0; i < bn; i++) {
    cin >> b[i];
  }
  cin >> cn;
  vector<ll> c(cn);
  for (ll i = 0; i < cn; i++) {
    cin >> c[i];
  }
  cout << lcs3(a, b, c) << endl;
}
