#include <bits/stdc++.h>
using namespace std;
#define ll long long

// long long get_fibonacci_huge_naive(long long n, long long m) {
//     if (n <= 1)
//         return n;

//     long long previous = 0;
//     long long current  = 1;

//     for (long long i = 0; i < n - 1; ++i) {
//         long long tmp_previous = previous;
//         previous = current;
//         current = tmp_previous + current;
//     }

//     return current % m;
// }


ll int fun(ll int ans , ll int n){
    if(n == 0)return 0;
    else if(n == 1)return 1;
    else if(n == 2){ 
        ans = ans%3;
        if (ans == 0) return 0;
        else if(ans == 1) return 1;
        else if(ans == 2) return 1;
    }    
    else{
        ll count = 2;
        ll int a = 0,b = 1,c;
        // b is F(n) and a is F(n-1) and c is temp
        for(ll int i=2;i <= 6*n + 1;i++){
            c = (b%n + a%n)%n;
            a = b;
            b = c;
            if(b == 1 && a == 0){
                count--;
                break;
            }else{
                count++;
            }
        }
        ans  = ans % count;
        a = 0, b = 1;
        for(ll int i=2;i <= ans;i++){
            c = (b%n + a%n)%n;
            a = b;
            b = c;
        }
        return b;
    }
}

int main(void) {
    long long int n, m;
    cin >> n >> m;
    // cout << n % fun(m) << '\n';
    cout<<fun(n,m)<<"\n";
}
