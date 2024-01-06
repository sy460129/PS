#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int m[10001];
vector<int>v;
int main(){
	int t, n, c; cin >> t;
	while(t--){
		cin >> n;
		v.resize(n);
		for(int i=0; i<n; i++) cin >> v[i];
		cin >> c;
		sort(v.begin(), v.end());
		for(int i=0; i<v.size(); i++){
			m[v[i]]++;
			for(int j=1; j<=c; j++){
				if(v[i]>j) continue;
				m[j]+=m[j-v[i]];
			}
		}
		cout << m[c] << "\n";
		v.clear();
		fill(m, m+10001, 0);
	}
}