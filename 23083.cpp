#include<iostream>
using namespace std;
unsigned long long arr[1002][1002];
bool hole[1001][1001];
int main() {
	int n,m,k,x,y;
	cin >> n >> m >> k;
	while(k--){
		cin >> x >> y;
		hole[x][y]=true;
	}
	arr[1][1]=1;
	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			if((i==1 && j==1) || hole[j][i]){
				continue;
			}
			if(i%2!=0){
				if(i==1){
					arr[j][i]=arr[j-1][i];
				}
				else{
					arr[j][i]=(arr[j-1][i-1] + arr[j-1][i]  + arr[j][i-1]) % 1000000007;
				}
			}
			else{
				arr[j][i]=(arr[j][i-1] + arr[j-1][i] + arr[j+1][i-1]) % 1000000007;
			}
		}
	}
	cout << arr[n][m];
}