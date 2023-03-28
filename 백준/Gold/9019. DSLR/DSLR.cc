#include <iostream>
#include <queue>
using namespace std;
bool check[10001], ch;
queue<pair<int,string>>q;
int n, m, t;
void bfs() {
	while(!q.empty()){
		int a, b, x=q.front().first;
		string c=q.front().second;
		q.pop();
		if(!ch){
			a=x;
			a*=2;
			a%=10000;
			if(a==m){
				ch=true;
				cout << c+"D" << "\n";
			}
			else if(!check[a]) q.push({a,c+"D"}), check[a]=true;
		}
		if(!ch){
			a=x;
			a--;
			if(a<0) a=9999;
			if(a==m){
				ch=true;
				cout << c+"S" << "\n";
			}
			else if(!check[a]) q.push({a,c+"S"}), check[a]=true;
		}
		if(!ch){
			a=x%1000, b=x/1000;
			a=a*10+b;
			if(a==m){
				ch=true;
				cout << c+"L" << "\n";
			}
			else if(!check[a]) q.push({a,c+"L"}), check[a]=true;
		}
		if(!ch){
			a=x/10, b=x%10;
			a=b*1000+a;
			if(a==m){
				ch=true;
				cout << c+"R" << "\n";
			}
			else if(!check[a]) q.push({a,c+"R"}), check[a]=true;
		}
		if(ch){
			while(!q.empty()) q.pop();
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while(t--){
		cin >> n >> m;
		check[n]=true;
		ch=false;
		q.push({n,""});
		bfs();
		fill(check, check+10001, false);
	}
}