#include <iostream>
using namespace std;
char arr[1001][1001];
int n, m, cnt;
int main(){
	cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> arr[i][j];
		}
	}
	for(int i=1; i<n; i++){
		for(int j=1; j<m; j++){
			cnt=0;
			if(arr[i][j]==arr[i][j-1]) cnt++;
			if(arr[i][j]==arr[i-1][j]) cnt++;
			if(arr[i][j]==arr[i-1][j-1]) cnt++;
			if(cnt==2){
				cout << "BaboBabo";
				return 0;
			}
			else if(cnt==0){
				if(arr[i-1][j-1]==arr[i-1][j] && arr[i][j-1]==arr[i-1][j]){
					cout << "BaboBabo";
					return 0;
				}
			}
		}
	}
	cout << "dd";
}