#include<bits/stdc++.h>
using namespace std;

int get_change(int m) {
  int n = 0;
  if(m >= 10){
  	n += m/10;
  	m%=10;
  }
  if(m>=5){
  	n += m/5;
  	m%=5;
  }
  if(m>=1){
  	n+=m;
  }
  return n;
}

int main(void) {
  int m;
  cin >> m;
  cout << get_change(m) << '\n';
}
