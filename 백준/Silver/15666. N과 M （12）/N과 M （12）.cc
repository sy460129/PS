#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, x;
vector<int>v, vec;
void dfs(int t){
	if(vec.size()==m){
		for(auto & e : vec){
			cout << e << " ";
		}
		cout << "\n";
		return;
	}
	int p=-1;
	for(int i=t; i<n; i++){
		if(p!=v[i]){
			vec.push_back(v[i]);
			p=v[i];
			dfs(i);
			vec.pop_back();
		}
	}
}
int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	dfs(0);
}