#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(long long int i=a;i<b;i++)
#define sz(s) (long long int)(s).size()
#define pb push_back
#define mp make_pair
#define ll long long int
const ll inf = 1000000000;
const ll MOD = 1000000007;
vector<ll> key2;
vector<ll> left2;
vector<ll> right2;
struct Node{
  ll data;
  Node* left;
  Node* right;
  Node* parent;
};
Node* make_tree(Node* root,ll key1,ll left1,ll right1){
  Node* temp = new Node();
  temp->data = key1;
  temp->parent = root;
  if(left1 == -1){
    temp->left = nullptr;
  }else{
    temp->left = make_tree(temp,key2[left1],left2[left1],right2[left1]);
  }
  if(right1 == -1){
    temp->right = nullptr;
  }else{
    temp->right = make_tree(temp,key2[right1],left2[right1],right2[right1]);
  }
  return temp;

}
ll height(Node* node){
  if (node == nullptr) 
       return 0;
   else{     
       ll lDepth = height(node->left);
       ll rDepth = height(node->right);    
       if (lDepth > rDepth) 
           return(lDepth+1);
       else return(rDepth+1);
   }
}
void preorder_traversal(Node* node){
  if(node == NULL)return;
  cout<<node->data<<" ";
  preorder_traversal(node->left);
  preorder_traversal(node->right);
}

vector<ll> da;
void inorder_traversal(Node* node){
  if(node == NULL)return;
  inorder_traversal(node->left);
  // cout<<node->data<<" ";
  da.push_back(node->data);
  inorder_traversal(node->right);
}
void postorder_traversal(Node* node){
  if(node == NULL)return;
  postorder_traversal(node->left);
  postorder_traversal(node->right);
  cout<<node->data<<" ";
}
// struct Node* newnode(int data,Node* root) {
//  struct Node* temp = new Node();
//  temp -> data = data;
//  temp -> left = NULL;
//  temp -> right = NULL;
//  temp -> parent = root;
//  return temp;
// };
int main(void){
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    cout.tie(NULL);
    register ll i,j,x,y,m,n,t,k,sum=0,max,min,count=0,temp,w,q;
    cin>>t;
    if(t == 0){
      cout<<"CORRECT\n";
      return 0;
    }
    while(t--){
      cin >> x >> y >> k;
      key2.push_back(x);
      left2.push_back(y);
      right2.push_back(k);
    }
    Node* root = new Node();
    root->parent = nullptr;
    root = make_tree(root,key2[0],left2[0],right2[0]);
    
    // cout<< root->data << " " << root->left->data <<" "<< root->right->data <<" "<<root->left->left->data <<" " <<root->left->right->data;
    // cout<<"\n";
    // cout<<height(root)<<"\n";    
    inorder_traversal(root);
    // cout<<"\n";
    // preorder_traversal(root);
    // cout<<"\n";
    // postorder_traversal(root);
    // cout<<"\n";
    for(i=1;i<da.size();i++){
      if(da[i] < da[i-1]){
        cout<<"INCORRECT\n";
        return 0;
      }
    }
    cout<<"CORRECT\n";
}    
