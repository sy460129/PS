#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int arr[32001];
vector<int>v[32001];
queue<int>q;
int main(){
    int n, m, x, y;
    cin >> n >> m;
    while(m--){
        cin >> x >> y;
        arr[y]++;
        v[x].push_back(y);
    }
    for(int i=1; i<=n; i++){
        if(arr[i]==0) q.push(i);
    }
    while(!q.empty()){
        x=q.front(); q.pop();
        cout << x << " ";
        for(int i=0; i<v[x].size(); i++){
            arr[v[x][i]]--;
            if(arr[v[x][i]]==0) q.push(v[x][i]);
        }
    }
}