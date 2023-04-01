#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int>v[100001], v2[100001];
bool check[100001], check2[100001];
queue<int>q;
int n, m;
void dfs(){
	while(!q.empty()){
		int x=q.front(); q.pop();
		for(int i=0; i<v[x].size(); i++){
			if(!check[v[x][i]]){
				q.push(v[x][i]);
				check[v[x][i]]=true;
			}
		}
	}
}
void dfs2(){
	while(!q.empty()){
		int x=q.front(); q.pop();
		for(int i=0; i<v2[x].size(); i++){
			if(!check2[v2[x][i]]){
				q.push(v2[x][i]);
				check2[v2[x][i]]=true;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int x, y; cin >> n >> m;
	while(m--){
		cin >> x >> y;
		v[x].push_back(y);
		v2[y].push_back(x);
		if(x==1) check[1]=true;
	}
	q.push(1);
	dfs();
	q.push(n);
	dfs2();
	cin >> m;
	while(m--){
		cin >> x;
		(check[1] && check[x] && check2[x]) ? cout << "Defend the CTP\n" : cout << "Destroyed the CTP\n";
	}
}