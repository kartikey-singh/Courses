#include<bits/stdc++.h>
using namespace std;
#define ll long long int

// string largest_number(vector<string> a) {
//   //write your code here
//   // sort
//   return result;
// }
bool cmp( const  string &a, const  string &b ) {
    // if(a.length() == b.length()){
    //   return a < b;
    // }
    return a+b < b+a;
    // return a.second < b.second ;
}



int main(void) {
  int n;
  string s;
  cin >> n;
  vector<string> a;
  for (size_t i = 0; i < n; i++) {
    cin >> s;
    a.push_back(s);
  }
  // cout<<a.size()<<"\n";
  sort(a.begin(), a.end(),cmp);
  for (size_t i = 0; i<n ;i++) {
    cout<< a[a.size()-i-1];
  }
  cout<<"\n";
  // cout << largest_number(a);
}
