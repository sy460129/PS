#include <iostream>
using namespace std;
int arr[1000][1000];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int n, t, a, b, cnt=0;
void bfs(){
	int i=0, x=0, y=0;
	while(1){
		if(i==0){
			while(x+dx[i]<n-cnt && x+dx[i]>=0){
				if(arr[x+dx[i]][y]!=0){
					break;
				}
				arr[x+dx[i]][y]=arr[x][y]-1;
				x+=dx[i];
				if(arr[x][y]==t){
					a=x, b=y;
				}
			}
			i++;
		}
		if(i==1){
			while(y+dy[i]<n-cnt && y+dy[i]>=0){
				if(arr[x][y+dy[i]]!=0){
					break;
				}
				arr[x][y+dy[i]]=arr[x][y]-1;
				y+=dy[i];
				if(arr[x][y]==t){
					a=x, b=y;
				}
			}
			i++;
		}
		if(i==2){
			while(x+dx[i]<n-cnt && x+dx[i]>=0){
				if(arr[x+dx[i]][y]!=0){
					break;
				}
				arr[x+dx[i]][y]=arr[x][y]-1;
				x+=dx[i];
				if(arr[x][y]==t){
					a=x, b=y;
				}
			}
			i++;
		}
		cnt++;
		if(i==3){
			while(y+dy[i]<n-cnt && y+dy[i]>=0){
				if(arr[x][y+dy[i]]!=0){
					break;
				}
				arr[x][y+dy[i]]=arr[x][y]-1;
				y+=dy[i];
				if(arr[x][y]==t){
					a=x, b=y;
				}
			}
			i++;
		}
		i=0;
		if(n==cnt){
			break;
		}
	}
}
int main(){
	cin >> n >> t;
	arr[0][0]=n*n;
	bfs();
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << a + 1<< " " << b + 1;
}