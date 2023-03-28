#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int arr[101][101];
bool num[101];
vector<pair<int,int>>v;
int t, k;
bool check(int x, int y){
	for(int i=0; i<k; i++){
		for(int j=0; j<k; j++){
			if(arr[i][j]==0) continue;
			if(!num[arr[i][j]]) num[arr[i][j]]=true;
			else return false;
		}
		fill(num, num+101, false);
	}
	for(int j=0; j<k; j++){
		for(int i=0; i<k; i++){
			if(arr[i][j]==0) continue;
			if(!num[arr[i][j]]) num[arr[i][j]]=true;
			else return false;
		}
		fill(num, num+101, false);
	}
	return true;
}
bool dfs(int x, int y){
	for(int l=0; l<k; l++){
		for(int i=x; i<x+t; i++){
			for(int j=y; j<y+t; j++){
				if(arr[i][j]==0) continue;
				if(!num[arr[i][j]]) num[arr[i][j]]=true;
				else return false;
			}
		}
		fill(num, num+101, false);
		y+=t;
		if(y==k) y=0, x+=t;
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> t;
	k=t*t;
	for(int i=0; i<k; i++) {
		for(int j=0; j<k; j++) {
			cin >> arr[i][j];
		}
	}
	if(dfs(0, 0) && check(0,0)) cout << "CORRECT";
	else cout << "INCORRECT";
}