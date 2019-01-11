#include <bits/stdc++.h>
using namespace std;
#define ll long long

// int fibonacci_sum_squares_naive(long long n) {
//     if (n <= 1)
//         return n;

//     long long previous = 0;
//     long long current  = 1;
//     long long sum      = 1;

//     for (long long i = 0; i < n - 1; ++i) {
//         long long tmp_previous = previous;
//         previous = current;
//         current = tmp_previous + current;
//         sum += current * current;
//     }

//     return sum % 10;
// }
ll int fun(ll int n){
    if(n == 0)return 0;
    else if(n == 1)return 1;
    else{
        ll int a = 0,b = 1,c;
        for(ll int i=2;i<=n;i++){
            c = (b%10 + a%10)%10;
            a = b;
            b = c;
        }
        return c;
    }
}
int main() {
    ll int n = 0;
    cin >> n;
    cout << ( (fun(n%60)%10) * (fun( (n+1)%60 )%10) )%10<<endl;
}
