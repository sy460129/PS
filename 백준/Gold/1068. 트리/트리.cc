#include <iostream>
#include <vector>
using namespace std;
vector<int>v[51];
int n, t, x, cnt;
void dfs(int cur){
    for(int i=0; i<v[cur].size(); i++){
        if(v[cur][i]==x){
            if(v[cur].size()==1) cnt++;
        }
        else dfs(v[cur][i]);
    }
    if(v[cur].size()==0) cnt++;
}
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x;
        if(x==-1) t=i;
        else v[x].push_back(i);
    }
    cin >> x;
    if(x==t){
        cout << 0;
        return 0;
    }
    dfs(t);
    cout << cnt;
}