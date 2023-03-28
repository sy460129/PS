#include <iostream>
using namespace std;
int arr[101][10001];
pair<int,int>a[2], b[2];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin >> arr[i][j];
			if(i==1){
				if(arr[i][j]>a[0].first){
					swap(a[0],a[1]);
					a[0]={arr[i][j],j};
				}
				else if(arr[i][j]>a[1].first) a[1]={arr[i][j],j};
			}
		}
	}
	for(int i=2; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(a[0].second!=j) arr[i][j]+=arr[i-1][a[0].second];
			else arr[i][j]+=arr[i-1][a[1].second];
			if(b[0].first<arr[i][j]){
				swap(b[0],b[1]);
				b[0]={arr[i][j],j};
			}
			else if(b[1].first<arr[i][j]) b[1]={arr[i][j],j};
		}
		a[0]=b[0], a[1]=b[1];
		b[0]={0,0}, b[1]={0,0};
	}
	int ans=-1;
	for(int i=1; i<=m; i++) ans=max(ans, arr[n][i]);
	cout << ans;
}