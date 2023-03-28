#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
int x;
char arr[4]={' ','+','-'};
vector<char>v;
vector<string>vec;
queue<int>q;
void dfs(){
	if(v.size()==x-1){
		string t;
		for(int i=1; i<=x; i++){
			t+=(i+'0');
			if(i==x){
				vec.push_back(t);
				continue;
			}
			if(v[i-1]=='+'){
				vec.push_back(t), t="";
				q.push(i-1);
			}
			else if(v[i-1]=='-'){
				vec.push_back(t), t="";
				q.push(i-1);
			}
		}
		int cnt=1, ans=stoi(vec[0]);
		while(!q.empty()){
			int x=q.front(); q.pop();
			if(v[x]=='+') ans+=stoi(vec[cnt]);
			else if(v[x]=='-') ans-=stoi(vec[cnt]);
			cnt++;
		}
		if(ans==0){
			for(int i=1; i<x; i++){
				cout << i << v[i-1];
			}
			cout << x << "\n";
		}
		while(!vec.empty()) vec.pop_back();
		return;
	}
	for(int i=0; i<3; i++){
		v.push_back(arr[i]);
		dfs();
		v.pop_back();
	}
}
int main(){
	int n; cin >> n;
	while(n--){
		cin >> x;
		for(int i=0; i<3; i++){
			v.push_back(arr[i]);
			dfs();
			v.pop_back();
		}
		cout << "\n";
	}
}