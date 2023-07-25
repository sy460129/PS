#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
bool cube[126][126][126];
vector<tuple<int,int,int>>v;
int main(){
	int n, m, a, b, c, cnt=0; cin >> n >> m;
	for(int i=0; i<m; i++){
		cin >> a >> b >> c;
		cube[a][b][c]=true;
		v.push_back({a,b,c});
	}
	for(auto e : v){
		a=get<0>(e), b=get<1>(e), c=get<2>(e);
		if(cube[a+1][b][c] && cube[a-1][b][c] && cube[a][b+1][c] && cube[a][b-1][c] && cube[a][b][c+1] && cube[a][b][c-1]) cnt++;
	}
	cout << cnt;
}