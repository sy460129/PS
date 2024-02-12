#include <iostream>
#include <vector>
using namespace std;
vector<int>v[300001];
bool tree[300001];
int n, x, y;
long long w, e;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i=0; i<n-1; i++){
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1; i<=n; i++){
		tree[i]=true;
		if(v[i].size()>=3){
			long long t=v[i].size();
			w+=t*(t-1)*(t-2)/6;
		}
		if(v[i].size()!=1){
			for(int j=0; j<v[i].size(); j++){
				if(!tree[v[i][j]] && v[v[i][j]].size()!=1) {
					e+=(v[i].size()-1)*(v[v[i][j]].size()-1);
				}
			}
		}
	}
	if(e==3*w) cout << "DUDUDUNGA";
	else e>3*w ? cout << "D" : cout << "G";
}