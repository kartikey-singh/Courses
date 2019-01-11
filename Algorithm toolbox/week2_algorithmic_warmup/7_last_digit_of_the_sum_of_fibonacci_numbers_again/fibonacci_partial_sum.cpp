#include <bits/stdc++.h>
using namespace std;
#define ll long long

// long long get_fibonacci_partial_sum_naive(long long from, long long to) {
//     long long sum = 0;

//     long long current = 0;
//     long long next  = 1;

//     for (long long i = 0; i <= to; ++i) {
//         if (i >= from) {
//             sum += current;
//         }

//         long long new_current = next;
//         next = next + current;
//         current = new_current;
//     }

//     return sum % 10;
// }
ll int fun(ll int n){
    // ll int fib[n+3] = {0};
    // fib[0]=0;
    // fib[1]=1;   
    if(n <= 0)return 0;
    else if(n == 1)return 1;
    else if(n == 2)return 2;
    else{
        ll int a = 0,b = 1,c;
        for(ll int i=2;i<=n+2;i++){
            c = (b%10 + a%10)%10;
            a = b;
            b = c;
        }
        if (c == 0)c = 9;
        else c = c - 1;
        return c;
    }
}
int main() {
    long long from, to,from1,to1;
    std::cin >> from >> to;
    from1 = fun((from-1)%60 );
    to1 = fun(to%60);
    // if(from1 == 0 && from - 1 != 0)from1 = 10;
    // if(to1 == 0 )to1 = 10;
    if(from == to && from == 0){
        cout<<0<<"\n";
    }
    else if(to1 == from1 && to1 == 0){
        cout<<0<<"\n";
    }
    else if(to1 <= from1){
        to1 += 10;
        cout << to1 - from1 << '\n';
    }else{
        cout << to1 - from1 << '\n';
    }
}
