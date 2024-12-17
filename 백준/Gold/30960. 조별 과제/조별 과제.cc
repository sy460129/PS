#include <iostream>
#include <algorithm>
using namespace std;
using ll=long long;
ll a[500001], dp[500001];
int ans, res;
int main(){
  int n, p, m=2147483647, v; cin >> n;
  for(int i=0; i<n; i++) cin >> a[i];
  sort(a, a+n);
  for(int i=1; i<n-3; i+=2) ans+=a[i]-a[i-1];
  ans+=a[n-1]-a[n-3];
  res=ans;
  for(int i=n-1; i>=4; i-=2){
    res-=a[i]-a[i-2];
    res+=a[i]-a[i-1];
    res-=a[i-3]-a[i-4];
    res+=a[i-2]-a[i-4];
    ans=min(res, ans);
  }
  cout << ans;
}