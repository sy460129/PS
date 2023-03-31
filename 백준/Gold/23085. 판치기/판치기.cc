#include <iostream>
#include <queue>
using namespace std;
int n, m, h, t, cnt = 1;
queue<pair<int,int>>q, q2;
bool visit[3001][3001];
void bfs(){
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		int k, l;
		q.pop();
		for(int i=0; i<=m; i++){
            if(x-i<0 || y-(m-i)<0 || x-i+(m-i)>3000 || y+i-(m-i)>3000) continue;
            else{
                k=x-i+(m-i);
                l=y+i-(m-i);
                if(!visit[k][l]) visit[k][l]=true, q2.push({k,l});
            }
		}
	}
}
int main() {
	string s;
	cin >> n >> m >> s;
	for(int i=0; i<n; i++){
		s[i]=='H' ? h++: t++;
	}
	if(h == 0){
		cout << 0 << "\n";
		return 0;
	}
	q.push({h,t});
	visit[h][t]=true;
	while(!q.empty()){
		bfs();
		while(!q2.empty()){
			int a=q2.front().first;
			int b=q2.front().second;
			if(a==0){
				cout << cnt << "\n";
				return 0;
			}
			q.push({a, b});
			q2.pop();
		}
		cnt++;
	}
	cout << -1 << "\n";
}