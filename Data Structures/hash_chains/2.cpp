#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(long long int i=a;i<b;i++)
#define sz(s) (long long int)(s).size()
#define pb push_back
#define mp make_pair
#define ll long long int
const ll inf = 1000000000;
const ll MOD = 1000000007;
ll hash1(string s,ll m){
    ll ans = 0;
    for(ll i =s.length()-1;i>=0;i--){
        ans = (ans*263 + s[i])%MOD;
    }
    return ans%m;
}

struct Node{
    string data;
    Node *next;
};

void find(Node* node,string search){
  while (node != nullptr){
     if(node->data == search){
        cout<<"yes\n";
        return;
     }
     node = node->next;
  }
  cout<<"no\n";
}
int find1(Node* node,string search){
  while (node != nullptr){
     if(node->data == search){
        // cout<<"yes\n";
        return 1;
     }
     node = node->next;
  }
  return 0;
  // cout<<";
}
void add(Node** head_ref, string new_data){
    if(find1(*head_ref,new_data) == 0){
        Node* new_node = new Node();
        new_node->data  = new_data;
        new_node->next = (*head_ref);
        (*head_ref)    = new_node;
    }
    return;
}

void del(Node** head_ref, string search){
    Node* temp = new Node();
    temp = *head_ref;
    Node* prev = new Node();
    if (temp != NULL && temp->data == search){
        *head_ref = temp->next;   
        delete temp;              
        return;
    }
    while (temp != NULL && temp->data != search){
        prev = temp;
        temp = temp->next;
    }
    if (temp == nullptr)return;
    prev->next = temp->next;
    delete temp; 
}

void check(Node* node){
  while (node != nullptr){
     cout << node->data << " ";
     node = node->next;
  }
  cout<<"\n";
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    cout.tie(NULL);
    register ll i,m,t,index;
    cin>>m>>t;
    Node* a[m];
    for(i=0;i<m;i++){
        a[i] = new Node();
    }
    // cout<<hash1("world",m);
    while(t--){
        string s,k;
        cin>>s;
        if(s == "add"){
            cin>>k;
            ll tt = hash1(k,m);
            add(&a[tt],k);
        }else if(s == "del"){
            cin>>k;
            ll tt = hash1(k,m);
            del(&a[tt],k);
        }else if(s == "check"){
            cin>>index;
            check(a[index]);
        }else{
            cin>>k;
            ll tt = hash1(k,m);
            find(a[tt],k);
        }
    }
}    
