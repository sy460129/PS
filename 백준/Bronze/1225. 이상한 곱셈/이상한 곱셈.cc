#include <iostream>
#include <queue>
#define rep(i, a, b) for(int i=a; i<b; i++)
using namespace std;
long long ans;
queue<int>q;
int x, y;
int main() {
	string s, c;
	cin >> s >> c;
	rep(i, 0, s.length()){
		q.push(s[i]-'0');
	}
	rep(i, 0, c.length()){
		y+=c[i]-'0';
	}
	while(!q.empty()){
		x=q.front();
		q.pop();
		ans+=x*y;
	}
	cout << ans;
}