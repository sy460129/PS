#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int t, n, m, x, y;
vector<int>v[20001];
int check[20001];
bool visit[20001];
queue<int>q;
bool bfs(){
    while(!q.empty()){
        int x=q.front(); q.pop();
        visit[x]=true;
        for(int j=0; j<v[x].size(); j++){
            if(!check[v[x][j]]) q.push(v[x][j]);
            if(check[x]==1){
                if(check[v[x][j]]==1) return false;
                else check[v[x][j]]=2;
            }
            else{
                if(check[v[x][j]]==2) return false;
                else check[v[x][j]]=1;
            }
        }
    }
    return true;
}
int main(){
	cin >> t;
	while(t--){
        bool flag=true;
        fill(check, check+20001, 0);
        fill(visit, visit+20001, 0);
        cin >> n >> m;
        for(int i=0; i<m; i++){
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        for(int i=1; i<=n; i++){
            if(!visit[i]){
                check[i]=1;
                q.push(i);
                bfs();
            }
        }
        for(int i=1; i<=n; i++){
            for(int j=0; j<v[i].size(); j++){
                if(check[v[i][j]]==check[i]) flag=false;
            }
            if(!flag) break;
        }
        flag ? cout << "YES\n" : cout << "NO\n";
        for(int i=1; i<=n; i++) v[i].clear();
    }
}