#include <iostream>
using namespace std;
int p[1000001];
int dp[1000001];
int find(int x){
    if(x==p[x]) return x;
    else return x=find(p[x]);
}
void merge(int x, int y){
    x=find(p[x]);
    y=find(p[y]);
    if(x!=y){
        x>y ? p[x]=y, dp[y]+=dp[x] : p[y]=x, dp[x]+=dp[y];
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    char c;
    int n, x, y;
    cin >> n;
    for(int i=1; i<=1000001; i++){
        p[i]=i, dp[i]=1;
    }
    while(n--){
        cin >> c;
        if(c=='I'){
            cin >> x >> y;
            merge(x, y);
        }
        else {
            cin >> x;
            cout << dp[x] << "\n";
        }
    }
}