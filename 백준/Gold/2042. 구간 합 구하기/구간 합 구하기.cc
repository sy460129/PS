#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll=long long;
ll init(vector<ll>&tree, vector<ll>&arr, int node, int s, int e){
	if(s==e){
		return tree[node]=arr[s];
	}
	int m=(s+e)/2;
	return tree[node]=init(tree, arr, node*2, s, m)+init(tree, arr, node*2+1, m+1, e);
}
void update(vector<ll>& tree, int node, int s, int e, int index, ll d){
	if(!(index<=e && index>=s)) return;
	tree[node]+=d;
	if(s<e){
		int m=(s+e)/2;
		update(tree, node*2, s, m, index, d);
		update(tree, node*2+1, m+1, e, index, d);
	}
}
ll sum(vector<ll>&tree, int node, int s, int e, int f, int l){
	if(l<s || f>e) return 0;
	else if(f<=s && e<=l) return tree[node];
	int m=(s+e)/2;
	return sum(tree, node*2, s, m, f, l)+sum(tree, node*2+1, m+1, e, f, l);
}
int main(){
	int n, m, k; cin >> n >> m >> k;
	m+=k;
	int h=(int)(ceil(log2(n)));
	int t=(1 << (1+h));
	vector<ll>arr(n);
	vector<ll>tree(t);
	for(int i=0; i<n; i++) cin >> arr[i];
	init(tree, arr, 1, 0, n-1);
	ll a, b, c;
	while(m--){
		cin >> a >> b >> c;
		if(a==1){
			ll d=c-arr[b-1];
			arr[b-1]=c;
			update(tree, 1, 0, n-1, b-1, d);
		}
		else{
			cout << sum(tree, 1, 0, n-1, b-1, c-1) << "\n";
		}
	}
}