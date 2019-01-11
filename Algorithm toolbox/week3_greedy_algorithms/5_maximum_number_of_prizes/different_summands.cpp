#include<bits/stdc++.h>
using namespace std;
#define ll long long int
// nice code think deeply about it how elegant it is
vector<ll> optimal_summands(ll n) {
  vector<ll> summands;
  ll count =0,last=1,t = n;
  //write your code here
  // while(n!=0){
  //   if(n - last >= 0){
  //     n -= last;
  //     if(last  == n){
  //     n+=last;
  //     last++;
  //    }
  //   }
  // }
  for(ll i=1;i<=n;i++){
    n -= i;
    if(n<=i){   // the conditon i becomes greater than n so you just add the last valueof n example 5
      summands.push_back(n+i);  
      break;
    }else if(n == 0){ // the conditon when n becomes 0 so you just add the i s it is the last element example 6
      summands.push_back(i);
      break;
    }else{
      summands.push_back(i);
    }
  }
  return summands;
}

int main() {
  ll n;
  cin >> n;
  vector<ll> summands = optimal_summands(n);
  cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    cout << summands[i] << ' ';
  }
  cout<<"\n";
}
