#include <iostream>
using namespace std;
int arr[51][51];
int main(){
	char c;
	int n, m, t=1, ans=1; cin >> n >> m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> c;
			arr[i][j]=c-'0';
		}
	}
	while (1) {
		for(int i=0; i<n-t; i++){
			for(int j=0; j<m-t; j++){
				if(arr[i][j]==arr[i+t][j] && arr[i][j]==arr[i][j+t] && arr[i][j]==arr[i+t][j+t]) ans=max(ans, (t+1)*(t+1));
			}
		}
		t++;
		if(t>n-1 || t>m-1) break;
	}
	cout << ans;
}