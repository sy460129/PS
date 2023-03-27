#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int init(vector<int>&arr, vector<int>&tree, int node, int s, int e){
	if(s==e){
		return tree[node]=arr[s];
	}
	int m=(s+e)/2;
	return tree[node]=init(arr, tree, node*2, s, m)+init(arr, tree, node*2+1, m+1, e);
}
void update(vector<int>&tree, int node, int s, int e, int i, int d){
	if(!(i>=s && i<=e)) return;
	tree[node]+=d;
	if(s<e){
		int m=(s+e)/2;
		update(tree, node*2, s, m, i, d);
		update(tree, node*2+1, m+1, e, i, d);
	}
}
int find(vector<int>&tree, int node, int s, int e, int f, int l){
	if(s>l || e<f) return 0;
	else if(s>=f && e<=l) return tree[node];
	int m=(s+e)/2;
	return find(tree, node*2, s, m, f, l)+find(tree, node*2+1, m+1, e, f, l);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, a, b, c, h; cin >> n;
	h=(int)(ceil(log2(n)));
	h=(1<<(1+h));
	vector<int>arr(n);
	vector<int>tree(h);
	for(int i=0; i<n; i++){
		cin >> a;
		arr[i]=a%2; // even = 0, odd = 1
	}
	init(arr, tree, 1, 0, n-1);
	cin >> m;
	while(m--){
		cin >> a >> b >> c;
		if(a==1){
			c%=2;
			if(arr[b-1]!=c){
				int diff=c-arr[b-1];
				arr[b-1]=c;
				update(tree, 1, 0, n-1, b-1, diff);
			}
		}
		else{
			int x=find(tree, 1, 0, n-1, b-1, c-1);
			a==3 ? cout << x << "\n" : cout << c-b-x+1 << "\n";
		}
	}
}