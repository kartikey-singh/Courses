#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(long long int i=a;i<b;i++)
#define sz(s) (long long int)(s).size()
#define pb push_back
#define mp make_pair
#define ll long long int
const ll inf = 1000000000;
const ll MOD = 1000000007;

ll hash1(string s,ll start,ll end,ll x){
    ll ans = 0;
    for(ll i = end;i>=start;i--){
        ans = (ans*x + s[i])%MOD ;
    }
    return ans;
}

vector<ll> prehash(string text,ll psize,ll x){
	ll y = 1,siz = text.length();
	vector<ll> hval(siz - psize+1,0);
	hval[hval.size() -1] = hash1(text,siz - psize,siz-1,x);
	for(ll i=0;i<psize;i++){
		y = (y*x)%MOD;
	}
	for(ll i = hval.size()-2;i>=0;i--){
		hval[i] = (x*hval[i+1] + text[i] - y*text[i+psize])%MOD;
		if(hval[i]<0){
			hval[i] = (hval[i] + MOD)%MOD;
		}
	}
	return hval;
}

int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    cout.tie(NULL);
    register ll i,j,x;
    string pattern,text;
    cin>>pattern>>text;
    // x = rand()%(MOD-1) + 1;
    x =17;
    ll phash = hash1(pattern,0,pattern.length()-1,x);
    vector<ll> Hpat = prehash(text,pattern.length(),x);
    vector<ll> result;
    for(i=0;i<text.length()-pattern.length()+1;i++){
    	if(phash != Hpat[i])continue;
		ll flag = 0;
		for(j=0;j<pattern.length();j++){
			if(pattern[j] != text[i+j]){
				flag = 1;
				break;
			}
		}if(flag == 0)result.push_back(i);
    }
    for(i=0;i<result.size();i++){
    	cout<<result[i]<<" ";
    }
}    
