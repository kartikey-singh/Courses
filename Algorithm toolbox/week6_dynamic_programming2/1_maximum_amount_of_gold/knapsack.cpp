#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll max1(ll a,ll b){
  return (a>b)?a:b;
}
ll optimal_weight(ll W, const vector<ll> &w) {
  ll dp[w.size()+1][W+1];
  for(ll i=0;i < w.size()+1;i++){
    for(ll j=0;j < W + 1 ;j++){
      if(i == 0 || j == 0)dp[i][j]=0;
      else if(j >= w[i-1]){
        // cout<<i<<" "<<w[i-1]<<" "<<dp[i][j - w[i-1] ]+w[i-1]<<" "<<dp[i-1][j]<<" \n";
        dp[i][j] = max1(dp[i-1][j - w[i-1]]+w[i-1],dp[i-1][j]);
      }else{
        dp[i][j] = dp[i-1][j];
      }

    }
  }
  // cout<<"yoo\n";
  // for(ll i=0 ;i < w.size()+1;i++){
  //   for(ll j=0;j<W+1;j++){
  //     cout<<dp[i][j]<<" ";
  //   }
  //   cout<<"\n";
  // }

  // for (size_t i = 0; i < w.size(); ++i) {
  //   if (current_weight + w[i] <= W) {
  //     current_weight += w[i];
  //   }
  // }
  return dp[w.size()][W];
}

int main(void) {
  ll n, W;
  cin >> W >> n;
  vector<ll> w(n);
  for (ll i = 0; i < n; i++) {
    cin >> w[i];
  }

  ll N = n + 1;
  ll M = W + 1;

  ll** dp = new ll*[N];
  
  for(ll i = 0; i < N; ++i)
      dp[i] = new ll[M];
 
  // for(int i = 0; i < N; ++i)
  //   for(int j = 0; j < M; ++j)
  //     ary[i][j] = i;

  for(ll i=0;i<N;i++){
    for(ll j=0;j<M;j++){
      if(i == 0 || j == 0)dp[i][j]=0;
      else if(j >= w[i-1]){
        dp[i][j] = max1(dp[i-1][j - w[i-1]]+w[i-1],dp[i-1][j]);
      }else{
        dp[i][j] = dp[i-1][j];
      }
    }
  } 
  
  cout<<dp[N-1][M-1]<<"\n";
  
  // for(int i = 0; i < N; ++i)
  //   for(int j = 0; j < M; ++j)
  //     std::cout << ary[i][j] << "\n";
  
  for(int i = 0; i < N; ++i)
    delete [] dp[i];
  delete [] dp;
  // cout << optimal_weight(W, w) << '\n';
}
