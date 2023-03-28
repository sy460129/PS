#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, t, x; cin >> t;
	for(int i=1; i<=t; i++){
		vector<int>v;
		cin >> n;
		for(int j=0; j<n; j++){
			cin >> x;
			if(v.empty() || v.back()<x) v.push_back(x);
			else{
				auto it=lower_bound(v.begin(), v.end(), x)-v.begin();
				v[it]=x;
			}
		}
		cout << "Case #" << i << ": " << n-v.size() << "\n";
	}
}