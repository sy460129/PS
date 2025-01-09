#include <iostream>
#include <vector>
using namespace std;
int c[30001], dp[30001], cnt[30001], ans[30001][3001];
vector<int>v;
int find(int x){
    if(dp[x]==x) return dp[x];
    else return find(dp[x]);
}
void merge(int x, int y){
    x=find(dp[x]);
    y=find(dp[y]);
    if(x!=y) x<y ? dp[y]=x : dp[x]=y;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, k, a, b; cin >> n >> m >> k;
    for(int i=1; i<=n; i++){
        cin >> c[i];
        dp[i]=i;
    }
    while(m--){
        cin >> a >> b;
        merge(a, b);
    }
    for(int i=1; i<=n; i++){
        dp[i]=find(i);
        if(dp[i]!=i) c[dp[i]]+=c[i], cnt[dp[i]]++;
        else cnt[i]=1, v.push_back(i);
    }
    for(int i=1; i<=v.size(); i++){
        for(int j=1; j<k; j++){
            if(j<cnt[v[i-1]]) ans[i][j]=max(ans[i-1][j], ans[i][j-1]);
            else ans[i][j]=max(ans[i-1][j], ans[i-1][j-cnt[v[i-1]]]+c[v[i-1]]);
        }
    }
    cout << ans[v.size()][k-1] << "\n";
}