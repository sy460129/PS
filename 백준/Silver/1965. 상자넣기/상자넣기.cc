#include <iostream>
#include <vector>
using namespace std;
vector<int>v;
int main(){
	int n, x; cin >> n;
	for(int i=0; i<n; i++){
		cin >> x;
		if(v.empty() || v.back()<x) v.push_back(x);
		else{
			auto it=lower_bound(v.begin(), v.end(), x)-v.begin();
			v[it]=x;
		}
	}
	cout << v.size();
}