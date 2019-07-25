#include<bits/stdc++.h>
#define ll long long int
#define mp make_pair
using namespace std;
ll min1(ll a,ll b){
	return (a<b)?a:b;
}
ll edit_distance(const string &str1, const string &str2) {
  ll m = str1.length(),n = str2.length(),i,j;
  ll dp[m+1][n+1];
  for(i=0;i<n+1;i++)dp[0][i] = i;
  for(i=0;i<m+1;i++)dp[i][0] = i;

  for(i=1;i<m+1;i++){
  	for(j=1;j<n+1;j++){
  		if(str1[i-1] == str2[j-1]){
        // cout<<i-1<<" "<<j-1<<" "<<str1[i-1]<<"\n";
  			dp[i][j] = min1(dp[i-1][j] + 1,min1(dp[i-1][j-1],dp[i][j-1]+1));
  		}else{
  			// dp[i][j] = min1(dp[i-1][j] + 1,min1(dp[i-1][j-1]+1,dp[i][j-1]+1));
        dp[i][j] = min1(dp[i-1][j] + 1,min(dp[i][j-1]+1,dp[i-1][j-1]+1));
  		}
  	}
  }	
  for(i=0;i<m+1;i++){
  	for(j=0;j<n+1;j++){
  		cout<<dp[i][j]<<" ";
  	}
  	cout<<"\n";
  }
  return dp[m][n];
}

int main(void) {
  string str1;
  string str2;
  cin >> str1 >> str2;
  cout << edit_distance(str1, str2) << endl;
}