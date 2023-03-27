#include <iostream>
#include <vector>
using namespace std;
vector<int>v[51];
int n, x, h, cnt;
void dfs(int cur){
	if(v[cur].empty()){
		cnt++;
		return;
	}
	for(int i=0; i<v[cur].size(); i++){
		if(v[cur][i]==x){
			if(v[cur].size()==1) cnt++;
		}
		else dfs(v[cur][i]);
	}
}
int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> x;
		if(x==-1) h=i;
		else v[x].push_back(i);
	}
	cin >> x;
	if(x==h){
		cout << 0;
		return 0;
	}
	dfs(h);
	cout << cnt;
}