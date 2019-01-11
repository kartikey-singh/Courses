#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(long long int i=a;i<b;i++)
#define sz(s) (long long int)(s).size()
#define pb push_back
#define mp make_pair
#define ll long long int
const ll inf = 1000000000;
const ll MOD = 1000000007;
string a[10000000];
int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    cout.tie(NULL);
    register ll i,y,t;
    cin>>t;
    FOR(i,0,10000000)a[i] = "-1";
    while(t--){
    	string s,k;
    	cin>>s;
    	if(s == "add"){
    		cin>>y>>k;
    		a[y] = k;
    	}else if(s == "find"){
    		cin>>y;
    		if(a[y] == "-1"){
    			cout<<"not found\n";
    		}else{
    			cout<<a[y]<<"\n";
    		}
    	}else{
    		cin>>y;
    		if(a[y]!= "-1"){
    			a[y] = "-1";
    		}
    	}
    }
}    
