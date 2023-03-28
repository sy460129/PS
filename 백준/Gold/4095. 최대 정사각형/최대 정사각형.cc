#include <iostream>
using namespace std;
int arr[1001][1001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m,x;
	while(1){
		cin >> n >> m;
		x=0;
		if(n==0 && m==0){
			return 0;
		}
		else{
			for(int i=1; i<=n; i++){
				for(int j=1; j<=m; j++){
					cin >> arr[i][j];
				}
			}
			for(int i=1; i<=n; i++){
				for(int j=1; j<=m; j++){
					if(arr[i][j]==1 && arr[i-1][j-1]!=0 && arr[i-1][j]!=0 && arr[i][j-1]!=0){
						arr[i][j]=min(arr[i-1][j-1], min(arr[i-1][j],arr[i][j-1]))+1;
					}
					x=max(x,arr[i][j]);
				}
			}
		}
		cout << x << "\n";
		fill(&arr[0][0], &arr[n][m], 0);
	}
}