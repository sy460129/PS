#include <iostream>
using namespace std;
int arr[101][101];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int n, x, y, cnt = 0;
void bfs(int a, int b){
	for(int i=0; i<4; i++){
		int x=a+dx[i];
		int y=b+dy[i];
		if(arr[x][y]==0){
			cnt++;
		}
	}
}
int main(){
	cin >> n;
	while(n--){
		cin >> x >> y;
		for(int i=x; i<x+10; i++){
			for(int j=y; j<y+10; j++){
				arr[i][j]=1;
			}
		}
	}
	for(int i=0; i<100; i++){
		for(int j=0; j<100; j++){
			if(arr[i][j]==1){
				bfs(i,j);
			}
		}
	}
	cout << cnt;
}