#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[101];
bool check[101];
vector<int>v;
int main(){
    int n, m, x, y, cnt=0; cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> x;
        if(arr[x]==0) v.push_back(x), cnt++;
        if(v.size()>n){
            int k=1001;
            for(int i=0; i<v.size()-1; i++){
                if(k>arr[v[i]] && check[v[i]]){
                    k=arr[v[i]];
                    y=v[i];
                }
            }
            auto it=find(v.begin(), v.end(), y);
            v.erase(it);
            arr[y]=0;
            check[y]=false;
            cnt--;
        }
        arr[x]++;
        check[x]=true;
    }
    for(int i=1; i<101; i++){
        if(check[i]) cout << i << " ";
    }
}