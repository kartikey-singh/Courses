#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll get_change(ll m) {
	ll total[m+1],num=0;
	total[0] = 0;
	for(ll i=1;i<m+1;i++)total[i]=INT_MAX;
	ll coins[] = {1,3,4};
	for(ll i=1;i<m+1;i++){
		for(ll j=0;j<3;j++){
			if(i >= coins[j]){
				num = total[i-coins[j]] + 1; 
				if(num < total[i]){
					total[i] = num;
				}
			}
		}
	}
	// for(ll i=0;i<m+1;i++)cout<<total[i]<<" ";
	return total[m];
}

int main(void) {
	ll m;
  	cin >> m;
  	cout << get_change(m) << '\n';
}
