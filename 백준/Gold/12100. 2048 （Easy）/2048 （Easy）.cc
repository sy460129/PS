#include <iostream>
#include <cstring>
using namespace std;
int arr[21][21];
int n, ans;
void dfs(int t, int cnt){
	int dp[21][21];
	if(cnt==5) {
		return;
	}
	for(int k=0; k<4; k++){
		if(k==0){
			memcpy(dp, arr, sizeof(dp));
			for(int i=0; i<n; i++){
				int p=0;
				for(int j=0; j<n; j++){
					if(arr[i][j]!=0){
						if(p==0){
							if(arr[i][p]==0) swap(arr[i][p],arr[i][j]);
							else if(j!=0){
								if(arr[i][j]==arr[i][p]) arr[i][p]*=2, arr[i][j]=0, p++;
								else{
									if(arr[i][p]!=0) p++;
									swap(arr[i][p],arr[i][j]);
								}
							}
						} 
						else {
							if(arr[i][j]==arr[i][p]) arr[i][p]*=2, arr[i][j]=0, p++;
							else{
								if(arr[i][p]!=0) p++;
								swap(arr[i][p],arr[i][j]);
							}
						}
					}
				}
			}
			dfs(t, cnt+1);
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					ans=max(ans,arr[i][j]);
					arr[i][j]=dp[i][j];
				}
			}
		}
		else if(k==1){
			memcpy(dp, arr, sizeof(dp));
			for(int i=0; i<n; i++){
				int p=n-1;
				for(int j=n-1; j>=0; j--){
					if(arr[i][j]!=0){
						if(p==n-1){
							if(arr[i][p]==0) swap(arr[i][p],arr[i][j]);
							else if(j!=n-1){
								if(arr[i][j]==arr[i][p]) arr[i][p]*=2, arr[i][j]=0, p--;
								else{
									if(arr[i][p]!=0) p--;
									swap(arr[i][p],arr[i][j]);
								}
							}
						}
						else {
							if(arr[i][j]==arr[i][p]) arr[i][p]*=2, arr[i][j]=0, p--;
							else{
								if(arr[i][p]!=0) p--;
								swap(arr[i][p],arr[i][j]);
							}
						}
					}
				}
			}
			dfs(t, cnt+1);
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					ans=max(ans,arr[i][j]);
					arr[i][j]=dp[i][j];
				}
			}
		}
		if(k==2){
			memcpy(dp, arr, sizeof(dp));
			for(int j=0; j<n; j++){
				int p=0;
				for(int i=0; i<n; i++){
					if(arr[i][j]!=0){
						if(p==0){
							if(arr[p][j]==0) swap(arr[p][j],arr[i][j]);
							else if(i!=0){
								if(arr[i][j]==arr[p][j]) arr[p][j]*=2, arr[i][j]=0, p++;
								else{
									if(arr[p][j]!=0) p++;
									swap(arr[p][j],arr[i][j]);
								}
							}
						}
						else {
							if(arr[i][j]==arr[p][j]) arr[p][j]*=2, arr[i][j]=0, p++;
							else{
								if(arr[p][j]!=0) p++;
								swap(arr[p][j],arr[i][j]);
							}
						}
					}
				}
			}
			dfs(t, cnt+1);
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					ans=max(ans,arr[i][j]);
					arr[i][j]=dp[i][j];
				}
			}
		}
		if(k==3){
			memcpy(dp, arr, sizeof(dp));
			for(int j=0; j<n; j++){
				int p=n-1;
				for(int i=n-1; i>=0; i--){
					if(arr[i][j]!=0){
						if(p==n-1){
							if(arr[p][j]==0) swap(arr[p][j],arr[i][j]);
							else if(i!=n-1){
								if(arr[i][j]==arr[p][j]) arr[p][j]*=2, arr[i][j]=0, p--;
								else{
									if(arr[p][j]!=0) p--;
									swap(arr[p][j],arr[i][j]);
								}
							}
						} 
						else {
							if(arr[i][j]==arr[p][j]) arr[p][j]*=2, arr[i][j]=0, p--;
							else{
								if(arr[p][j]!=0) p--;
								swap(arr[p][j],arr[i][j]);
							}
						}
					}
				}
			}
			dfs(t, cnt+1);
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					ans=max(ans,arr[i][j]);
					arr[i][j]=dp[i][j];
				}
			}
		}
	}
}
int main(){
	cin >> n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> arr[i][j];
		}
	}
	for(int i=0; i<4; i++) dfs(i, 0);
	cout << ans;
}