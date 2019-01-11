#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(long long int i=a;i<b;i++)
#define sz(s) (long long int)(s).size()
#define pb push_back
#define mp make_pair
#define ll long long int
const ll inf = 1000000000;
const ll MOD = 1000000007;
struct tt{
	int at;
	int ft;
	int i;
};
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    cout.tie(NULL);
    register ll i,j,x,y,m,n,t,k,sum=0,max,min,count=0,temp,w,s;
    cin>>s>>n;
    deque <tt> q;
    vector <tt> v;
    if(n != 0){
	    for(i=0;i<n;i++){
	    	tt a;
	    	cin>>a.at>>a.ft;
	    	a.i = i;
	    	v.pb(a);
	    }
	    ll b[n]={0};
	    for(i=0;i<n;i++){
			while(!q.empty()){
				if(q.front().ft <= v[i].at)q.pop_front();
				else break;
			}
			if(q.size() == s){
				b[v[i].i] = -1;
			}else if(q.empty()){
				v[i].ft = v[i].ft + v[i].at;
				q.push_back(v[i]);
				b[v[i].i] = v[i].at;
			}else{
				// convert proccesing time into final time
				v[i].ft = q.back().ft + v[i].ft;
				b[v[i].i] = q.back().ft;
				q.push_back(v[i]);	
			}
		}
		for(i=0;i<n;i++){
			cout<<b[i]<<"\n";
		}
	}	
		return 0;
}    