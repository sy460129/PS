#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long brr[100001];
int n, m, k;
vector<long long>v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> k;
		v.push_back(k);
	}
	sort(v.begin(), v.end());
	for(int i=1; i<=n; i++){
		if(i==1){
			brr[i]=v[i-1];
			continue;
		}
		brr[i]+=v[i-1]+brr[i-1];
	}
	while(m--){
		cin >> k;
		auto it= lower_bound(v.begin(), v.end(), k)-v.begin();
		cout << abs((brr[n]-brr[it])-k*(n-it)+k*(it)-brr[it]) << "\n";
	}
}