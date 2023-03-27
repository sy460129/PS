#include <iostream>
using namespace std;
int arr[101][101];
int INF=5000001;
int main() {
	int n, m, a, b, res, ans=INF, x;
	cin >> n >> m;
	fill(&arr[0][0], &arr[101][101], INF);
	while(m--){
		cin >> a >> b;
		arr[a][b]=1;
		arr[b][a]=1;
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			for(int k=1; k<=n; k++){
				if(arr[j][i]+arr[i][k] < arr[j][k]){
					arr[j][k]=arr[j][i]+arr[i][k];
				}
			}
		}
	}
	for(int i=1; i<=n; i++){
		res=0;
		for(int j=1; j<=n; j++){
			res+=arr[i][j];
		}
		if(res<ans){
			ans=res;
			x=i;
		}
	}
	cout << x;
}