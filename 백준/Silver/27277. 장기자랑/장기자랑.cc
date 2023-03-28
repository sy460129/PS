#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int n, k=0, ans=0; cin >> n;
	vector<int>v(n), vec;
	for(int i=0; i<n; i++) cin >> v[i];
	sort(v.begin(), v.end());
	int f=0, e=n-1;
	while(f<=e) {
		k%2==0 ? vec.push_back(v[e]) : vec.push_back(v[f]);
		k%2==0 ? e-- : f++;
		k++;
	}
	ans=vec[0];
	for(int i=1; i<n; i++) {
		ans+=max(0, vec[i]-vec[i-1]);
	}
	cout << ans;
}