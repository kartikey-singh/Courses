#include<bits/stdc++.h>
#define ll long long int
#define mp make_pair
using namespace std;
ll min1(ll a,ll b){
  return (a < b)? a:b;
}
ll min2(ll a,ll b,ll i,ll j){
  return (a<b)?i:j;
}
void calc(ll n){
  ll total[n+1]={0};
  total[0] = LONG_MAX;
  vector<ll> v;
  for(ll i = 2; i < n+1; i++){
    if(i%3 == 0 && i%2 == 0){
      total[i] = min1(total[i-1]+1, min1(total[i/2]+1, total[i/3]+1));
    }else if(i%3 == 0){
      total[i] = min1(total[i-1]+1,total[i/3]+1);
    }else if(i%2 == 0){
      total[i] = min1(total[i-1]+1,total[i/2]+1);
    }else{
      total[i] = total[i-1]+1;
    }
    // cout<<i<<" "<<total[i-1]<<" "<<total[i/2]<<" "<<total[i/3]<<" "<<total[i]<<"\n";
  } 
  cout<<total[n]<<"\n";
  ll temp = 0;
  while(n >= 1){
    v.push_back(n);
    if(n%3 == 0 && n%2 == 0){
      if(total[n/2] < total[n/3]){
        temp = min2(total[n-1],total[n/2],n-1,n/2);
      }else{
        temp = min2(total[n-1],total[n/3],n-1,n/3);
      }
    }else if(n%3 == 0){     
      temp = min2(total[n-1],total[n/3],n-1,n/3);
    }else if(n%2 == 0){   
      temp = min2(total[n-1],total[n/2],n-1,n/2);
    }else{   
      temp = n-1;
    }
    n = temp;
  }
  reverse(v.begin(), v.end());
  for(ll i=0;i<v.size();i++){
    cout<<v[i]<<" ";
  }
  cout<<"\n";
}

vector<int> optimal_sequence(int n) {
  vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main(void) {
  int n;
  cin >> n;
  calc(n);
  // vector<int> sequence = optimal_sequence(n);
  // cout << sequence.size() - 1 << std::endl;
  // for (size_t i = 0; i < sequence.size(); ++i) {
  //   cout << sequence[i] << " ";
  // }
}