#include <iostream>
using namespace std;
int arr[3001][3001];
int dp[3001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, q, x, a, b, c;
    cin >> n >> m >> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
        dp[i]=i;
    }
    while(q--){
        cin >> x;
        if(x==0){
            cin >> a >> b >> c;
            arr[dp[a]][b]=c;
        }
        else{
            cin >> a >> b;
            int t=dp[b];
            dp[b]=dp[a], dp[a]=t;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << arr[dp[i]][j] << " ";
        }
        cout << "\n";
    }
}