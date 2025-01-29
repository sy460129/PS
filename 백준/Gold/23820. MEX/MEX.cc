#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool check[2222222];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	long long x;
	vector<long long>v;
	while(n--){
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<v.size(); j++){
			x=v[i]*v[j];
			if(x>2000003) break;
			else check[x]=1;
		}
	}
	for(int i=0; i<=2000003; i++){
		if(!check[i]){
			cout << i;
			break;
		}
	}
}