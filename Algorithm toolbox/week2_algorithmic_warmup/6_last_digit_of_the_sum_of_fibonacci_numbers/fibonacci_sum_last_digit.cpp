#include <bits/stdc++.h>
using namespace std;
#define ll long long
// int fibonacci_sum_naive(long long n) {
//     if (n <= 1)
//         return n;

//     long long previous = 0;
//     long long current  = 1;
//     long long sum      = 1;

//     for (long long i = 0; i < n - 1; ++i) {
//         long long tmp_previous = previous;
//         previous = current;
//         current = tmp_previous + current;
//         sum += current;
//     }

//     return sum % 10;
// }
ll int fun(ll int n){
    // ll int fib[n+3] = {0};
    // fib[0]=0;
    // fib[1]=1;   
    if(n == 0)return 0;
    else if(n == 1)return 1;
    else if(n == 2)return 2;
    else{
        ll int a = 0,b = 1,c;
        for(ll int i=2;i<=n+2;i++){
            c = (b%10 + a%10)%10;
            a = b;
            b = c;
        }
        if (c == 0)c = 9;  // as f[n+2] if 0 then -1 give negative otput-1
        else c = c - 1;
        return c;
    }
}
// int fun(int n){
//     int fib[n+1] = {0};
//     fib[0]=0;
//     fib[1]=1;
//     cout<<fib[0]<<","<<fib[1]<<",";
//     for(int i=2;i<=n;i++){
//         fib[i] = (fib[i-1]%10 + fib[i-2]%10)%10;
//         cout<<fib[i]<<",";
//     }
//     cout<<"\n";
//     return fib[n];
// }
// ll int fun(ll int n){
// }

int main(void) {
    ll int n = 0;
    cin >> n;
    cout << fun(n%60)<<endl;
}
