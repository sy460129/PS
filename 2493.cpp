#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int,int>>v;
queue<int>q;
int main() {
	int n, x;
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> x;
		while(!v.empty() && x>v.back().first){
			v.pop_back();
		}
		if(v.empty()){
			q.push(0);
		}
		else{
			q.push(v.back().second);
		}
		v.push_back({x,i});
	}
	while(!q.empty()){
		cout << q.front() << " ";
		q.pop();
	}
}