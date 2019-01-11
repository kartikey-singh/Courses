#include<bits/stdc++.h>
using namespace std;
class Node;
class Node {
public:
    int key;
    Node *parent;
    vector<Node *> children;
    Node() {
      this->parent = NULL;
    }
    void setParent(Node *theParent) {
      parent = theParent;
      parent->children.push_back(this);
    }
};
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);   
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<Node> nodes(n);
  for (int child_index = 0; child_index < n; child_index++) {
    int parent_index;
    cin >> parent_index;
    if (parent_index >= 0)
      nodes[child_index].setParent(&nodes[parent_index]);
    nodes[child_index].key = child_index;
  }
  register int maxHeight = 0,height1[n] = {0};
  for (int leaf_index = 0; leaf_index < n; leaf_index++) {
    int height = 0;
    if(height1[leaf_index] == 0){
      for (Node *v = &nodes[leaf_index]; v != NULL; v = v->parent){
        if(height1[v->key] == 0){
          height++; 
        }else{
          height += height1[v->key];
          break;
        }
      }
      height1[leaf_index] = height; 
    }else{
      height = height1[leaf_index];
    } 
    maxHeight = max(maxHeight, height);
  } 
  cout << maxHeight << endl;
}
