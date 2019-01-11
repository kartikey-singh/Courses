#include<bits/stdc++.h>
using namespace std;
#define ll long long int

// ll partition3(vector<ll> &A,ll sum) {
// 	ll dp[A.size()+1][sum/3+1][sum/3+1];
// 	for(ll i = 0 ; i < A.size() + 1;i++){
// 		for(ll j=0;j < sum/3 + 1;j++){
// 			for(ll k=0;k< sum/3 + 1;k++){
// 				if(j == 0 || k == 0)dp[i][j][k] = 0;
// 				else if(i == 0)dp[i][j][k] = 1;
// 				else if(j >= A[i-1] && k >= A[i-1] ){
// 					dp[i][j][k] = dp[i-1][j][k] || dp[i-1][j-A[i-1]][k] || dp[i-1][j][k - A[i-1]];
// 				}else if(j >= A[i-1]){
// 					dp[i][j][k] = dp[i-1][j][k] || dp[i-1][j-A[i-1]][k] || dp[i-1][j][k];
// 				}
// 				else if(k>= A[i-1]){
// 					dp[i][j][k] = dp[i-1][j][k] || dp[i-1][j][k] || dp[i-1][j][k - A[i-1]];
// 				}
// 				else{
// 					dp[i][j][k] = dp[i-1][j][k];
// 				}
// 			}
// 		}
// 	}
//   	return dp[A.size()][sum/3][sum/3];
// }

// Partition problem states that if we can find a subset of set equal to sum/2 either by including an 
// element of subset or not as (x1,x2 ... xn-1) == sum or (x1,x2,... xn-1) == sum - xn then we set 
// the dp[i][j] to true for 2 way partition problem

ll partition3(vector<ll> &A,ll sum){
	if(sum%3 != 0)return 0;
	ll dp[A.size() + 1][sum/3 + 1];
	for(ll i=0;i<A.size()+1;i++)dp[i][0]=0;
	for(ll i=0;i<sum/3+1;i++)dp[0][i]=0;	
	for(ll i = 1;i < A.size() + 1;i++){
		for(ll j=1;j < sum/3 + 1;j++){
			// if(i == 0|| j == 0)dp[i][j] = 0;
			// else if(j = 0)dp[i][j] = 0;
			
			// else if(j > A[i-1]){
			
			if(A[i-1] == j || ( (j - A[i-1])>0 && dp[i-1][j-A[i-1]] ) ){
				if(dp[i-1][j] == 0)dp[i][j] = 1;
				else dp[i][j] = 2;
			}else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return (dp[A.size()][sum/3] == 2)? 1 : 0;
}

int main(void) {
	ll n,sum=0;
  	cin >> n;
  	vector<ll> A(n);
  	for (size_t i = 0; i < A.size(); ++i){
	  	cin >> A[i];
	  	sum+=A[i];
	}
	cout << partition3(A,sum) << '\n';
}
