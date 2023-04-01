#include <iostream>
#include <vector>
using namespace std;
int arr[4];
vector<int>v, vec;
int n, x, ma=-1000000001, mi=1000000001;
void dfs(){
	if(vec.size()==n-1){
		int res=v[0];
		for(int i=0; i<vec.size(); i++){
			if(vec[i]==0) res+=v[i+1];
			else if(vec[i]==1) res-=v[i+1];
			else if(vec[i]==2) res*=v[i+1];
			else if(vec[i]==3) res/=v[i+1];
		}
		mi=min(mi, res);
		ma=max(ma, res);
		return;
	}
	for(int i=0; i<4; i++){
		if(arr[i]){
			vec.push_back(i);
			arr[i]--;
			dfs();
			arr[i]++;
			vec.pop_back();
		}
	}
}
int main(){
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> x;
		v.push_back(x);
	}
	for(int i=0; i<4; i++) cin >> arr[i];
	dfs();
	cout << ma << "\n" << mi;
}