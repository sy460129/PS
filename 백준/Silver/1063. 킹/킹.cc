#include <iostream>
#include <queue>
using namespace std;
int arr[9][9];
queue<pair<int,int>>q, q2;
int main(){
	string s, c, t;
	char a, b;
	int n, x, y, rx, ry;
	cin >> s >> c >> n;
	q.push({s[0]-'A',s[1]-'0'});
	q2.push({c[0]-'A',c[1]-'0'});
	while(n--){
		x=q.front().first, y=q.front().second;
		rx=q2.front().first, ry=q2.front().second;
		cin >> t;
		if(t=="R"){
			if(x==7){
				continue;
			}
			else if(rx==x+1 && ry==y){
				if(rx!=7){
					q.pop();
					q.push({x+1, y});
					q2.pop();
					q2.push({rx+1, ry});
				}
			}
			else{
				q.pop();
				q.push({x+1, y});
			}
		}
		else if(t=="L"){
			if(x==0){
				continue;
			}
			else if(rx==x-1 && ry==y){
				if(rx!=0){
					q.pop();
					q.push({x-1, y});
					q2.pop();
					q2.push({rx-1, ry});
				}
			}
			else{
				q.pop();
				q.push({x-1, y});
			}
		}
		else if(t=="B"){
			if(y==1){
				continue;
			}
			else if(ry==y-1 && rx==x){
				if(ry!=1){
					q.pop();
					q.push({x, y-1});
					q2.pop();
					q2.push({rx, ry-1});
				}
			}
			else{
				q.pop();
				q.push({x, y-1});
			}
		}
		if(t=="T"){
			if(y==8){
				continue;
			}
			else if(ry==y+1 && rx==x){
				if(ry!=8){
					q.pop();
					q.push({x, y+1});
					q2.pop();
					q2.push({rx, ry+1});
				}
			}
			else{
				q.pop();
				q.push({x, y+1});
			}
		}
		if(t=="RT"){
			if(y==8 || x==7){
				continue;
			}
			else if(ry==y+1 && rx==x+1){
				if(ry!=8 && rx!=7){
					q.pop();
					q.push({x+1, y+1});
					q2.pop();
					q2.push({rx+1, ry+1});
				}
			}
			else{
				q.pop();
				q.push({x+1, y+1});
			}
		}
		if(t=="LT"){
			if(y==8 || x==0){
				continue;
			}
			else if(ry==y+1 && rx==x-1){
				if(ry!=8 && rx!=0){
					q.pop();
					q.push({x-1, y+1});
					q2.pop();
					q2.push({rx-1, ry+1});
				}
			}
			else{
				q.pop();
				q.push({x-1, y+1});
			}
		}
		if(t=="RB"){
			if(y==1 || x==7){
				continue;
			}
			else if(ry==y-1 && rx==x+1){
				if(ry!=1 && rx!=7){
					q.pop();
					q.push({x+1, y-1});
					q2.pop();
					q2.push({rx+1, ry-1});
				}
			}
			else{
				q.pop();
				q.push({x+1, y-1});
			}
		}
		if(t=="LB"){
			if(y==1 || x==0){
				continue;
			}
			else if(ry==y-1 && rx==x-1){
				if(ry!=1 && rx!=0){
					q.pop();
					q.push({x-1, y-1});
					q2.pop();
					q2.push({rx-1, ry-1});
				}
			}
			else{
				q.pop();
				q.push({x-1, y-1});
			}
		}
	}
	a=q.front().first+'A', y=q.front().second;
	b=q2.front().first+'A', ry=q2.front().second;
	cout << a << y << "\n" << b << ry;
}