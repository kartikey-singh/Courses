#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(long long int i=a;i<b;i++)
#define sz(s) (long long int)(s).size()
#define pb push_back
#define mp make_pair
#define ll long long int
const ll inf = 1000000000;
const ll MOD = 1000000007;
// void swap(ll *a,ll *b){
// 	ll temp = *a;
// 	*a = *b;
// 	*b = temp;
// }
vector< pair<ll,ll > > v;
ll count1 =0;
void print(ll a[],ll size){
	for(ll i=0;i<size;i++)cout<<a[i]<<" ";	
	cout<<"\n";    	
}
ll parent(ll i){
	return (i-1)/2;
}
ll leftchild(ll i){
	return 2*i+1;
}
ll rightchild(ll i){
	return 2*i+2;
}
void siftup(ll a[],ll i){
	while(i > 0 && a[parent(i)] < a[i] ){
		swap(a[parent(i)],a[i]);
		i = parent(i);
	}
}
// Below one also called the heapify procedure
void siftdown(ll a[],ll i,ll size){
	ll maxIndex = i;
	ll l = leftchild(i);
	// change the arrows to make desc or asec sort
	if(l < size && a[l] < a[maxIndex]) maxIndex = l;
	ll r = rightchild(i);
	if(r < size && a[r] < a[maxIndex]) maxIndex = r;
	if(i != maxIndex){
		count1++;
		v.pb(mp(i,maxIndex));
		swap(a[i],a[maxIndex]);
		siftdown(a,maxIndex,size);
	}
}
void insert(ll x,ll a[],ll size){
	if(size == INT_MAX){ // specify the maximum size of array
		cout<<"Overlimit\n";
	}
	size += 1;
	a[size-1] = x;
	siftup(a,size-1);
}
ll extractmax(ll a[],ll size){
	ll result = a[0];
	a[0] = a[size-1];
	size-=1;
	siftdown(a,0,size);
	return result;
}
void remove(ll i,ll a[],ll size){
	a[i] = inf;
	siftup(a,i);
	ll top = extractmax(a,size);
}
void changepriority(ll i,ll a[],ll p,ll size){
	ll oldp = a[i];
	a[i] = p;
	if(p > oldp) siftup(a,i);
	else siftdown(a,i,size);
}
void buildheap(ll a[],ll size){
    for(ll i=size/2-1;i>=0;i--){
		siftdown(a,i,size);
		// siftup(a,i);
    }	
}
void heapsort(ll a[],ll size){
	buildheap(a,size);
	print(a,size);
	for(ll i=size-1;i>=0;i--){
		swap(a[0],a[size-1]);
		size-=1;
		siftdown(a,0,size);
	}
}
// dynamically change size make it global and siftup not working in build heap

int main(void){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    cout.tie(NULL);
   	ll n;
    cin>>n;
    ll a[2*n]={0};
    for(ll i=0;i<n;i++)cin>>a[i];
    buildheap(a,n);
    // print(a,n);	
	cout<<count1<<"\n";
	if(count1 != 0){
		for(ll i =0;i<v.size();i++){
			cout<<v[i].first<<" "<<v[i].second<<"\n";
		}
	}
    // changepriority(3,a,6,n);
    // print(a,n);
  //  	heapsort(a,n);
 	// print(a,n);
 	// ll c = extractmax(a,n);
 	// print(a,n-1);
 	// heapsort(a,n-1);
 	// print(a,n-1);
}    