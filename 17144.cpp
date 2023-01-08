#include <iostream>
using namespace std;
int arr[51][51];
int dp[51][51];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
pair<int,int>v;
int main(){
    int n, m, t, x, y, k, ans=0; cin >> n >> m >> t;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
            dp[i][j]=arr[i][j];
            if(arr[i][j]==-1) v={i,j};
        }
    }
    while(t--){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                k=arr[i][j]/5;
                if(k>0){
                    for(int p=0; p<4; p++){
                        int nx=i+dx[p], ny=j+dy[p];
                        if(nx<0 || ny<0 || nx>n-1 || ny>m-1 || arr[nx][ny]==-1) continue;
                        dp[nx][ny]+=k, dp[i][j]-=k;
                    }
                }
            }
        }
        x=v.first, y=v.second;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                arr[i][j]=dp[i][j];
            }
        }
        int i=0, j=0;
        k=arr[i][j];
        while(j<m-1){
            arr[i][j]=arr[i][j+1];
            if(arr[i][j]==-1 || (i==x && j==y)) arr[i][j]=0;
            j++;
        }
        while(i<x-1){
            arr[i][j]=arr[i+1][j];
            if(arr[i][j]==-1 || (i==x && j==y)) arr[i][j]=0;
            i++;
        }
        while(j>0){
            arr[i][j]=arr[i][j-1];
            if(arr[i][j]==-1 || (i==x && j==y)) arr[i][j]=0;
            j--;
        }
        while(i>0){
			arr[i][j]=arr[i-1][j];
            if(arr[i][j]==-1 || (i==x && j==y)) arr[i][j]=0;
			i--;
		}
        i++;
        arr[i][j]=max(0,k);
        arr[x-1][y]=-1;
        i=x, j=0;
        k=arr[i][j];
        while(i<n-1){
            arr[i][j]=arr[i+1][j];
            if(arr[i][j]==-1 || (i==x && j==y)) arr[i][j]=0;
            i++;
        }
        while(j<m-1){
            arr[i][j]=arr[i][j+1];
            if(arr[i][j]==-1 || (i==x && j==y)) arr[i][j]=0;
            j++;
        }
        while(i>x){
            arr[i][j]=arr[i-1][j];
            if(arr[i][j]==-1 || (i==x && j==y)) arr[i][j]=0;
            i--;
        }
        while(j>0){
			arr[i][j]=arr[i][j-1];
            if(arr[i][j]==-1 || (i==x && j==y)) arr[i][j]=0;
			j--;
		}
        j++;
        arr[i][j]=max(0,k);
        arr[x][y]=-1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                dp[i][j]=arr[i][j];
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            ans+=arr[i][j];
        }
    }
    cout << ans+2;
}