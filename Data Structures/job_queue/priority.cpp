#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(long long int i=a;i<b;i++)
#define sz(s) (long long int)(s).size()
#define pb push_back
#define mp make_pair
#define ll long long int
const ll inf = 1000000000;
const ll MOD = 1000000007;
class CompareDist
{
public:
    bool operator()(pair<ll,ll> n1,pair<ll,ll> n2) {
    	if(n1.first == n2.first) return n1.second>n2.second;
    	return n1.first < n2.first;
    }
};
int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    cout.tie(NULL);
    register ll i,j,x,y,m,n,t,k,sum=0,max,min,count=0,temp,w,q;
 	cin>>n;
 	priority_queue< pair<ll,ll> ,vector<pair<ll,ll> >,CompareDist> p;
 	for(i=0;i<n;i++){
 		cin>>x>>y;
 		p.push(mp(x,y));
 	}
  	while (!p.empty())
  	{
     	cout<< p.top().first<<" "<<p.top().second<<"\n";
 		p.pop();
  	}
}    
