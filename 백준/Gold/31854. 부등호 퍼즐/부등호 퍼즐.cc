#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using p=pair<int,int>;
int idx[1001][1001];
int ans[1001][1001];
priority_queue<p, vector<p>, greater<p>>q;
vector<p>v[1001][1001];
int main(){
	int n; cin >> n;
	char c;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n-1; j++){
			cin >> c;
			if(c=='>')idx[i][j]++, v[i][j+1].push_back({i,j});
			else idx[i][j+1]++, v[i][j].push_back({i,j+1});
		}
	}
	for(int i=1; i<=n-1; i++){
		for(int j=1; j<=n; j++){
			cin >> c;
			if(c=='>')idx[i][j]++, v[i+1][j].push_back({i,j});
			else idx[i+1][j]++, v[i][j].push_back({i+1,j});
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(!idx[i][j]) q.push({i,j});
		}
	}
	int cur=1;
	while(!q.empty()){
		int x=q.top().first, y=q.top().second; q.pop();
		ans[x][y]=cur++;
		for(int i=0; i<v[x][y].size(); i++){
			auto ii=v[x][y][i];
			if(--idx[ii.first][ii.second]==0) q.push({ii.first, ii.second});
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}