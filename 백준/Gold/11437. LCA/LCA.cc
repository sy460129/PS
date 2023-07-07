#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dp[50001], p[50001];
vector<int>v[50001];
bool check[50001];
queue<int>q;
void depth(){
    while(!q.empty()){
        int x=q.front(); q.pop();
        for(int i=0; i<v[x].size(); i++){
            if(!check[v[x][i]]){
                check[v[x][i]]=true;
                dp[v[x][i]]=dp[x]+1;
                q.push(v[x][i]);
                p[v[x][i]]=x;
            }
        }
    }
}
void find(int a, int b){
    while(dp[a]!=dp[b]) b=p[b];
    while(a!=b) a=p[a], b=p[b];
    cout << a << "\n";
}
int main(){
    int n, m, a, b; cin >> n;
    for(int i=1; i<n; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    check[1]=true;
    q.push(1);
    depth();
    cin >> m;
    while(m--){
        cin >> a >> b;
        if(dp[a]>dp[b]) swap(a, b);
        find(a, b);
    }
}