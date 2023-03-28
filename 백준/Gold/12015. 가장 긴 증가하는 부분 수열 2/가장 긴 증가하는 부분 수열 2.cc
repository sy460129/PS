#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int main(){
	int n, x; cin >> n;
	v.push_back(-1);
	for(int i=1; i<=n; i++){
		cin >> x;
		if(v.back()<x){
			v.push_back(x);
		}
		else{
			auto it=lower_bound(v.begin(), v.end(), x)-v.begin();
			v[it]=x;
		}
	}
	cout << v.size()-1;
}