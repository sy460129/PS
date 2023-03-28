#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, x; cin >> n >> m;
	vector<pair<int,int>>v;
	vector<int>b, s;
	for(int i=1; i<=n; i++){
		cin >> x;
		v.push_back({x,i});
	}
	if(n==1){
		cout << "YES\n" << 1;
		return 0;
	}
	x=-1;
	sort(v.rbegin(), v.rend());
	for(int i=0; i<n-1; i++){
		if(v[i].first-v[i+1].first<=m) b.push_back(v[i].second);
		else {
			b.push_back(v[i].second);
			x=i;
			break;
		}
		if(i==n-2) b.push_back(v[i+1].second);
	}
	if(x==-1){
		cout << "YES\n";
		for(auto e : b) cout << e << " ";
		return 0;
	}
	else{
		x++;
		if(x<=3 || n<=4){
			cout << "NO";
			return 0;
		}
		else cout << "YES\n";
		for(int i=0; i<2; i++){
			cout << b.back() << " ";
			b.pop_back();
		}
		for(int i=x; i<n; i++) cout << v[i].second << " ";
		while(!b.empty()){
			cout << b.back() << " ";
			b.pop_back();
		}
	}
}