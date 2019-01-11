#include<bits/stdc++.h>
#define ll long long int
using namespace std;
class CompareDist
{
public:
    bool operator()(pair<ll,ll> n1,pair<ll,ll> n2) {
      if(n1.first == n2.first) return n1.second>n2.second;
      return n1.first > n2.first;
    }
};
class JobQueue {
 private:
  ll num_workers_;
  vector<ll> jobs_;
  vector<ll> assigned_workers_;
  vector<ll> start_times_;

  void WriteResponse() const {
    for (ll i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    ll m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(ll i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    // vector<ll> next_free_time(num_workers_, 0);
    
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    priority_queue< pair<ll ,ll > , vector<pair<ll,ll> >,CompareDist>ft;
    for(ll i = 0;i <  num_workers_;i++){
      ft.push(make_pair(0,i) );
    }
    for (ll i = 0; i < jobs_.size(); ++i) {
      assigned_workers_[i] = ft.top().second;
      start_times_[i] = ft.top().first;
      ft.pop();
      ft.push(make_pair(start_times_[i] + jobs_[i] , assigned_workers_[i] ));
    }



    // for (ll i = 0; i < jobs_.size(); ++i) {
    //   ll duration = jobs_[i];
    //   ll next_worker = 0;
    //   for (ll j = 0; j < num_workers_; ++j) {
    //     if (next_free_time[j] < next_free_time[next_worker])
    //       next_worker = j;
    //   }
    //   assigned_workers_[i] = next_worker;
    //   start_times_[i] = next_free_time[next_worker];
    //   next_free_time[next_worker] += duration;
    // }
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
