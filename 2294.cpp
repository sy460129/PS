#include <iostream>
#include <algorithm>
#define MAX 2147483647
using namespace std;
int arr[101];
int dp[10001];
int main(){
    int n, k; cin >> n >> k;
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);
    fill(dp, dp+10001, MAX);
    dp[0]=0;
    for(int i=0; i<n; i++){
        for(int j=arr[i]; j<=k; j++){
            if(dp[j-arr[i]]!=MAX) dp[j]=min(dp[j], dp[j-arr[i]]+1);
        }
    }
    if(dp[k]==MAX) dp[k]=-1;
    cout << dp[k];
}