#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>v[1000001], ans={4,7};
bool check;
int main() {
  v[4].push_back(4), v[7].push_back(7);
  int n, m; cin >> n;
  for(int i=8; i<=n; i++){
    m=i;
    check=1;
    while(m){
      if(!(m%10==4 || m%10==7)){
        check=0;
        break;
      }
      m/=10;
    }
    if(check) {
      v[i].push_back(i);
      ans.push_back(i);
    }
    else{
      for(int j=0; j<ans.size(); j++){
        if(!v[i-ans[j]].empty()){
          if(v[i].size()>=v[i-ans[j]].size()+2){
            v[i]=v[i-ans[j]];
            v[i].push_back(ans[j]);
          }
          else{
            if(!v[i].empty()) continue;
            v[i]=v[i-ans[j]];
            v[i].push_back(ans[j]);
          }
        }
      }
    }
  }
  if(v[n].empty()) cout << -1;
  else{
    sort(v[n].begin(), v[n].end());
    for(auto e : v[n]){
      cout << e << " ";
    }
  }
}