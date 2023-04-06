#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, x;
vector<int>v, vec;
bool check[9];
void dfs(){
	if(vec.size()==m){
		for(auto e : vec){
			cout << e << " ";
		}
		cout << "\n";
		return;
	}
	for(int i=0; i<n; i++){
		if(!check[i]){
			vec.push_back(v[i]);
			check[i]=true;
			dfs();
			vec.pop_back();
			check[i]=false;
		}
	}
}
int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	dfs();
}