#include <iostream>
#include <queue>
using namespace std;
using p=pair<int,int>;
priority_queue<p, vector<p>, greater<p>>q, q2;
int main(){
	int a, b, x, y, cnt=0;
	while(1){
		cin >> a >> b;
		if(a<0 && b<0) break;
		else if(!a && !b){
			while(!q.empty()){
				while(!q.empty()){
					x=q.top().first, y=q.top().second; q.pop();
					if(x>=a && y>=b) a=x, b=y;
					else q2.push({x,y});
				}
				cnt++;
				a=b=0;
				q=q2;
				while(!q2.empty()) q2.pop();
			}
			cout << cnt << "\n";
			cnt=0;
		}
		else q.push({a,b});
	}
}