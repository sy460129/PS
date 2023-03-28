#include <iostream>
#include <vector>
#define rep(i, a, b) for(int i=a; i<b; i++)
using namespace std;
int arr[101][101];
vector<pair<int,int>>v;
int main(){
	int n, x, y; cin >> n;
    rep(i, 0, n){
        rep(j, 0, n){
            cin >> arr[i][j];
            if(arr[i][j]==2){
                x=i, y=j;
            }
            else if(arr[i][j]==1) v.push_back({i,j});
        }
    }
    for(auto e : v){
        if(e.first%2==x%2 && e.second%2==y%2 || e.first%2!=x%2 && e.second%2!=y%2) {
            cout << "Kiriya";
            return 0;
        }
    }
    cout << "Lena";
}  