#include <iostream>
using namespace std;
int rkfh[101];
int tpfh[101];
int arr[101][101];
int n, m, t, p, ans=-2147483648;
int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
            rkfh[i]+=arr[i][j];
            tpfh[j]+=arr[i][j];
        }
    }
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            for(int k=0; k<m-1; k++){
                for(int l=k+1; l<m; l++){
                    t=min(j-i, l-k)-1;
                    p=max(j-i, l-k)-1;
                    ans=max(ans, rkfh[i]+rkfh[j]+tpfh[k]+tpfh[l]-(arr[i][k]+arr[i][l]+arr[j][k]+arr[j][l])+t*p);
                }
            }
        }
    }
    cout << ans;
}