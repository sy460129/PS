#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<int>v, vec;
bool check[9];
void dfs(int num){
	if(vec.size()==m){
		for(auto &e : vec){
			cout << e << " ";
		}
		cout << "\n";
		return;
	}
	for(int i=1; i<=n; i++){
		if(!check[i]){
			vec.push_back(i);
			check[i]=true;
			dfs(i);
			check[i]=false;
			vec.pop_back();
		}
	}
}
void track(){
	for(int i=1; i<=n; i++){
		vec.push_back(i);
		check[i]=true;
		dfs(i);
		check[i]=false;
		vec.pop_back();
	}
}
int main(){
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		v.push_back(i);
	}
	track();
}