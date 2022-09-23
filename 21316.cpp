#include <iostream>
#include <vector>
using namespace std;
vector<int>v[13];
int main(){
	int x, y, ans=0;
	for(int i=0; i<12; i++){
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1; i<=12; i++){
		if(v[i].size()==3){
			ans=0;
			for(int j=0; j<v[i].size(); j++){
				ans+=v[v[i][j]].size();
			}
			if(ans==6){
				cout << i;
				return 0;
			}
		}
	}
}