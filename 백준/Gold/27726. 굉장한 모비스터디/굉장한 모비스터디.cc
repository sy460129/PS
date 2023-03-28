#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <queue>
#include <algorithm>
using namespace std;
using t=tuple<int,int,int>;
int arr[3];
int dp[100001], dp2[100001], dp3[100001];
map<t, vector<int>>m;
vector<t>v;
vector<int>v2[100001];
int find(int x){
	if(x==dp[x]) return x;
	else return dp[x]=find(dp[x]);
}
void merge(int x, int y){
	x=find(dp[x]), y=find(dp[y]);
	if(x!=y){
		x<y ? dp[y]=x : dp[x]=y;
	}
}
int find2(int x){
	if(x==dp2[x]) return x;
	else return dp2[x]=find2(dp2[x]);
}
void merge2(int x, int y){
	x=find2(dp2[x]), y=find2(dp2[y]);
	if(x!=y){
		x<y ? dp2[y]=x : dp2[x]=y;
	}
}
int find3(int x){
	if(x==dp3[x]) return x;
	else return dp3[x]=find3(dp3[x]);
}
void merge3(int x, int y){
	x=find3(dp3[x]), y=find3(dp3[y]);
	if(x!=y){
		x<y ? dp3[y]=x : dp3[x]=y;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, x, y, z, k; cin >> n;
	for(int i=0; i<3; i++) cin >> arr[i];
	for(int i=1; i<=n; i++) dp[i]=i, dp2[i]=i, dp3[i]=i;
	for(int i=0; i<3; i++){
		for(int j=0; j<arr[i]; j++){
			cin >> x >> y;
			if(i==0) merge(x,y);
			else if(i==1) merge2(x,y);
			else merge3(x,y);
		}
	}
	for(int i=1; i<=n; i++){
		dp[i]=find(dp[i]);
		dp2[i]=find2(dp2[i]);
		dp3[i]=find3(dp3[i]);
		m[{dp[i],dp2[i],dp3[i]}].push_back(i);
		if(m[{dp[i],dp2[i],dp3[i]}].size()==2) v.push_back({dp[i],dp2[i],dp3[i]});
	}
	cout << v.size() << "\n";
	for(int i=0; i<v.size(); i++){
		auto cur=v[i];
		x=get<0>(cur);
		y=get<1>(cur);
		z=get<2>(cur);
		for(auto j=m[{x,y,z}].begin(); j!=m[{x,y,z}].end(); j++){
			int it=*j;
			if(j==m[{x,y,z}].begin()) k=it;
			v2[k].push_back(it);
		}
	}
	for(int i=1; i<=100000; i++){
		if(!v2[i].empty()){
			for(auto e : v2[i]) cout << e << " ";
			cout << "\n";
		}
	}
}