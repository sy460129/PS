#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n, ans, dp[100001], tree[1000001];
int init(int node, int s, int e){
	if(s==e) return tree[node]=s;
	int m=(s+e)/2;
	int l=init(node*2, s, m);
	int r=init(node*2+1, m+1, e);
	return tree[node]=dp[l]<dp[r] ? l : r;
}
int query(int node, int s, int e, int l, int r){
	if(l>e || r<s) return -1;
	if(s>=l && e<=r) return tree[node];
	int m=(s+e)/2;
	int r1=query(node*2, s, m, l, r);
	int r2=query(node*2+1, m+1, e, l, r);
	if(r1==-1) return r2;
	else if(r2==-1) return r1;
	else return dp[r1]<dp[r2] ? r1 : r2;
}
void solve(int l, int r){
	if(r<l) return;
	int idx=query(1, 0, n-1, l, r);
	ans=max(ans, dp[idx]*(r-l+1));
	solve(l, idx-1);
	solve(idx+1, r);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i=0; i<n; i++) cin >> dp[i];
	init(1, 0, n-1);
	solve(0, n-1);
	cout << ans;
}