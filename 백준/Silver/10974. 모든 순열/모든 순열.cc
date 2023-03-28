#include <iostream>
#include <vector>
using namespace std;
vector<int>v;
int n;
bool c[9];
void dfs(){
	if(v.size()==n){
		for(auto e : v) cout << e << " ";
		cout << "\n";
	}
	for(int i=1; i<=n; i++){
		if(!c[i]){
			c[i]=true;
			v.push_back(i);
			dfs();
			c[i]=false;
			v.pop_back();
		}
	}
}
int main(){
	cin >> n;
	dfs();
}