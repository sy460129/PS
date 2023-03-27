#include <iostream>
#include <queue>
#include <vector>
#define MAX 801
#define INF 2147483647
using namespace std;
typedef pair<int,int>p;
priority_queue<p, vector<p>, greater<p>>q;
vector<p>v[MAX];
int dist[MAX];
int dist2[MAX];
int dist3[MAX];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m, a, b, c, v1, v2;
	cin >> n >> m;
	while(m--){
		cin >> a >> b >> c;
		v[a].push_back({b,c});
		v[b].push_back({a,c});
	}
	cin >> v1 >> v2;
	q.push({0,v1});
	fill(dist2, dist2+MAX, INF);
	dist2[v1]=0;
	while(!q.empty()){
		int x=q.top().first, y=q.top().second;
		q.pop();
		for(int i=0; i<v[y].size(); i++){
			int next=v[y][i].first;
			int cost=v[y][i].second;
			if(dist2[next]>dist2[y]+cost){
				dist2[next]=dist2[y]+cost;
				q.push({dist2[next],next});
			}
		}
	}
	q.push({0,v2});
	fill(dist3, dist3+MAX, INF);
	dist3[v2]=0;
	while(!q.empty()){
		int x=q.top().first, y=q.top().second;
		q.pop();
		for(int i=0; i<v[y].size(); i++){
			int next=v[y][i].first;
			int cost=v[y][i].second;
			if(dist3[next]>dist3[y]+cost){
				dist3[next]=dist3[y]+cost;
				q.push({dist3[next],next});
			}
		}
	}
	if(dist2[1]==INF || dist2[v2]==INF || dist3[n]==INF ||
	dist3[1]==INF || dist2[n]==INF || dist3[v1]==INF){
		cout << -1;
		return 0;
	}
	cout << min(dist2[1]+dist2[v2]+dist3[n], dist3[1]+dist2[n]+dist3[v1]);
}