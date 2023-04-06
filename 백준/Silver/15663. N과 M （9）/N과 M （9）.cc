#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, x;
bool check[9];
vector<int>v, vec;
void dfs(){
	if(v.size()==m){
		for(auto e : v){
			cout << e << " ";
		}
		cout << "\n";
		return;
	}
	int p=-1;
	for(int i=0; i<n; i++){
		if(!check[i] && p!=vec[i]){
			v.push_back(vec[i]);
			check[i]=true;
			p=vec[i];
			dfs();
			check[i]=false;
			v.pop_back();
		}
	}
}
int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		cin >> x;
		vec.push_back(x);
	}
	sort(vec.begin(), vec.end());
	dfs();
}