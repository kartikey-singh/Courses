#include<bits/stdc++.h>
#define ll long long int
using namespace std;
// My implementation of merge sort

// void merge(vector<ll> &a,ll left,ll mid,ll right){
//   ll i = left,j=mid,k=left;
//   vector<ll> d = a;
//   while(i < mid && j < right){
//     if(d[i]<d[j]){
//       a[k] = d[i];
//       i++;
//     }else{
//       a[k] = d[j];  
//       j++;
//     }
//     k++;
//   }
//   while(i < mid){
//     a[k]=d[i];
//     i++;
//     k++;
//   }
//   while(j < right){
//     a[k]=d[j];
//     j++;
//     k++;
//   }
// }

// void mergesort(vector<ll> &a,ll left,ll right){
//   if(right - left <= 1) return; // A imp line for code working
//   ll mid = left + (right -left)/2;
//   mergesort(a,left,mid);
//   mergesort(a,mid,right);
//   merge(a,left,mid,right);

// }

// A working merge sort no. 2

// void mergeSort1(vector<ll>&left, vector<ll>& right, vector<ll>& bars)
// {
//     int nL = left.size();
//     int nR = right.size();
//     int i = 0, j = 0, k = 0;

//     while (j < nL && k < nR) 
//     {
//         if (left[j] < right[k]) {
//             bars[i] = left[j];
//             j++;
//         }
//         else {
//             count1++;
//             bars[i] = right[k];
//             k++;
//         }
//         i++;
//     }
//     while (j < nL) {
//         bars[i] = left[j];
//         j++; i++;
//     }
//     while (k < nR) {
//         bars[i] = right[k];
//         k++; i++;
//     }
// }
// void sort1(vector<ll> & bar) {
//     if (bar.size() <= 1) return;

//     int mid = bar.size() / 2;
//     vector<ll> left;
//     vector<ll> right;

//     for (size_t j = 0; j < mid;j++)
//         left.push_back(bar[j]);
//     for (size_t j = 0; j < (bar.size()) - mid; j++)
//         right.push_back(bar[mid + j]);

//     sort1(left);
//     sort1(right);
//     mergeSort1(left, right, bar);
// }


// long long merge1(){
//   long long i = left,j = ave,q = left;
//   for(i=left;i<right;i++)b[i]=a[i];   
//   i = left;  
//   while(i != ave && j != right){
//     if(b[i]<b[j]){
//       b[q] = a[i];
//       i++;
//       q++;
//     }else{
//       number_of_inversions++;
//       b[q] = a[j];
//       j++;
//       q++;
//     }
//   }
//   if(i != ave){
//     b[q]=a[i];
//     i++;
//     q++;
//   }else{
//     b[q]=a[j];
//     j++;
//     q++;
//   }
// }

// long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
//   long long number_of_inversions = 0;
//   if (right <= left + 1) return number_of_inversions;
//   size_t ave = left + (right - left) / 2;
//   number_of_inversions += get_number_of_inversions(a, b, left, ave);
//   number_of_inversions += get_number_of_inversions(a, b, ave, right);
//   //write your code here
  
//   return number_of_inversions;
// }

// // ll  count1 = 0;
// ll merge(vector<ll> &a,ll left,ll mid,ll right){
//   ll i = left,j=mid,k=left;
//   vector<ll> d = a;
//   ll count1 = 0;
//   while(i < mid && j < right){
//     if(d[i]<=d[j]){
//       a[k] = d[i];
//       i++;
//     }else{
      // cout<<mid<<" "<<i<<" "<<j<<" "<<d[i]<<" "<<d[j]<<"\n";
//       count1 += (mid - i);
//       a[k] = d[j];  
//       j++;
//     }
//     k++;
//   }
//   while(i < mid){
//     a[k]=d[i];
//     i++;
//     k++;
//   }
//   while(j < right){
//     a[k]=d[j];
//     j++;
//     k++;
//   }
//   return count1;
// }

// ll mergesort(vector<ll> &a,ll left,ll right){
//   if(right - left <= 1) return 0; // A imp line for code working
  
//   ll mid = left + (right -left)/2,num = 0;
//   num+=mergesort(a,left,mid);
//   num+=mergesort(a,mid,right);
//   num+=merge(a,left,mid,right);

// }

// My implementation of merge sort
ll count1 = 0;
void merge(vector<ll> &a,ll left,ll mid,ll right){
  ll i = left,j=mid,k=left;
  vector<ll> d = a;
  while(i < mid && j < right){
    if(d[i]<=d[j]){
      a[k] = d[i];
      i++;
    }else{
      // cout<<mid<<" "<<i<<" "<<j<<" "<<d[i]<<" "<<d[j]<<"\n";
      count1 += mid-i;
      a[k] = d[j];  
      j++;
    }
    k++;
  }
  while(i < mid){
    a[k]=d[i];
    i++;
    k++;
  }
  while(j < right){
    a[k]=d[j];
    j++;
    k++;
  }
}

void mergesort(vector<ll> &a,ll left,ll right){
  if(right - left <= 1) return; // A imp line for code working
  ll mid = left + (right -left)/2;
  mergesort(a,left,mid);
  mergesort(a,mid,right);
  merge(a,left,mid,right);

}

int main(void) {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    cin >> a[i];
  }
  // vector<int> b(a.size());
  // cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
  // sort1(a);
  mergesort(a,0,a.size());
  cout<<count1<<"\n";
  // for(ll i=0;i<a.size();i++){
  //   cout<<a[i]<<" ";
  // }
  // cout<<"\n";
}                                                                                                                                                                                               