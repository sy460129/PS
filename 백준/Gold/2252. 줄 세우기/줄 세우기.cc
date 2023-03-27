#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int arr[32001];
vector<int>v[32001];
queue<int>q;
int main(){
	int n, m, x, y;
	cin >> n >> m;
	while(m--){
		cin >> x >> y;
		v[x].push_back(y);
		arr[y]++;
	}
	for(int i=1; i<=n; i++){
		if(arr[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int nx=q.front();
		q.pop();
		cout << nx << " ";
		for(int i=0; i<v[nx].size(); i++){
			int ny=v[nx][i];
			arr[ny]--;
			if(arr[ny]==0){
				q.push(ny);
			}
		}
	}
}