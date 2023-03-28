#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[101][101];
bool visit[101][101];
int main(){
	int n, x, y, ans;
	while(1){
		ans=0;
		vector<pair<int,int>>v;
		fill(&visit[0][0], &visit[101][101], false);
		cin >> n;
		if(n==0) break;
		while(n--){
			cin >> x >> y;
			v.push_back({x,y});
			visit[x][y]=true;
		}
		sort(v.begin(), v.end());
		for(int i=0; i<v.size(); i++){
			int p=v[i].first, q=v[i].second;
			if(visit[p-1][q] && visit[p][q-1]) ans+=0;
			else if(visit[p-1][q] || visit[p][q-1]) ans+=2;
			else ans+=4;
		}
		cout << ans << "\n";
	}
}