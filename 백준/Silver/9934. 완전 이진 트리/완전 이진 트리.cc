#include <iostream>
#include <cmath>
using namespace std;
int arr[1024], cnt;
void dfs(int num, int s, int e, int c){
	if(c==num){
		cout << arr[(s+e)/2] << " ";
		return;
	}
	dfs(num, s, (s+e)/2, c+1);
	dfs(num, (s+e)/2+1, e, c+1);
}
int main(){
	int n, x; cin >> n;
	x=pow(2,n)-1;
	for(int i=0; i<x; i++) cin >> arr[i];
	for(int i=0; i<n; i++){
		dfs(i, 0, x, cnt);
		cout << "\n";
	}
}