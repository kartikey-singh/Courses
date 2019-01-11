#include <bits/stdc++.h>
using namespace std;
// long long lcm_naive(int a, int b) {
//   for (long l = 1; l <= (long long) a * b; ++l)
//     if (l % a == 0 && l % b == 0)
//       return l;
//   return (long long) a * b;
// }
long long int gcd(long long int a,long long int b){
	if(a == 0)return b;
	return gcd(b%a,a);
}
long long int lcm(long long int a,long long int b){
	long long int c = gcd(a,b);
	return (a*b)/c;
}
int main(void) {
  long long int a, b;
  cin >> a >> b;
  cout << lcm(a, b) << endl;
}
