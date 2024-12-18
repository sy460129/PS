#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
vector<int>v[21];
int main(){
  int n, x, t; cin >> n >> x;
  t=pow(2, n-1);
  if(t>x){
    cout << "impossible";
    return 0;
  }
  t>>=1;
  v[1].push_back(x);
  v[2].push_back(t);
  v[2].push_back(x-t);
  for(int i=3; i<=n; i++){
    for(int j=0; j<i-1; j++){
      v[i].push_back(v[i-1].front()/2);
    }
    v[i].push_back(v[i-1].back()-v[i].front());
  }
  for(int i=1; i<=n; i++){
    for(int j=0; j<v[i].size(); j++){
      cout << v[i][j] << " ";
    }
    cout << "\n";
  }
}