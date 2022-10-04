#include <iostream>
#include <vector>
using namespace std;
vector<int>v[201];
int arr[201];
bool check[201];
int n, m, x, y, cnt;
bool dfs(int n){
    for(int i=0; i<v[n].size(); i++){
        if(check[v[n][i]]) continue;
        check[v[n][i]]=true;
        if(arr[v[n][i]]==0 || dfs(arr[v[n][i]])){
            arr[v[n][i]]=n;
            return true;
        }
    }
    return false;
}
int main(){
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> x;
        while(x--){
            cin >> y;
            v[i].push_back(y);
        }
    }
    for(int i=1; i<=n; i++){
        fill(check, check+201, 0);
        if(dfs(i)){
            cnt++;
        }
    }
    cout << cnt;
}