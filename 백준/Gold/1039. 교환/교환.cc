#include <iostream>
#include <queue>
#include <string>
using namespace std;
queue<pair<string,int>>q, q2, q3;
bool c;
pair<string,int>p={"-1",0};
int m, n, arr[10];
void bfs(){
	int t=0;
	while(!q.empty()){
		while(!q.empty()){
			string k, x=q.front().first;
			int y=q.front().second;
			k=x;
			q.pop();
			if(p.first<=x && y<=m) p={x,y};
			if(y==m || t==n) continue;
			for(int i=t+1; i<n; i++){
				swap(x[t],x[i]);
				if(x[0]!='0') c=true;
				if(p.first[t]<=x[t]){
					if(x!=k) q2.push({x,y+1});
					else q2.push({x,y});
				}
				swap(x[t],x[i]);
			}
			q2.push({x,y});
		}
		q=q2, q2=q3;
		t++;
	}
}
int main() {
	string s;
	cin >> s >> m;
	q.push({s,0});
	n=s.length();
	bfs();
	if(p.second==m) cout << p.first;
	else if(!c) cout << -1;
	else{
		int y=p.second;
		c=false;
		for(int i=0; i<n; i++){
			arr[s[i]-'0']++;
			if(arr[s[i]-'0']>1) c=true;
		}
		if(c) cout << p.first;
		else{
			m-=y;
			if(m%2==0) cout << p.first;
			else{
				swap(p.first[n-1],p.first[n-2]);
				cout << p.first;
			}
		}
	}
}