#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, x, m;
	cin >> n;
	vector<int>v;
	for(int i=0; i<n; i++){
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	cin >> m;
	for(int i=0; i<m; i++){
		cin >> x;
		auto it=lower_bound(v.begin(), v.end()-1, x);
		*it==x ? cout << 1 << "\n" : cout << 0 << "\n";
	}
}