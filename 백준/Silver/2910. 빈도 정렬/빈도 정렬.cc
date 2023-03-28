#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
using p=pair<int,int>;
map<int,int>m;
vector<p>v;
bool cmp(p a, p b){
	if(m[a.first]==m[b.first]){
		return a.second<b.second;
	}
	return m[a.first]>m[b.first];
}
int main(){
	int n, c, x; cin >> n >> c;
	for(int i=0; i<n; i++){
		cin >> x;
		m[x]++;
		if(m[x]==1) v.push_back({x,i});
	}
	sort(v.begin(), v.end(), cmp);
	for(int i=0; i<v.size(); i++){
		for(int j=0; j<m[v[i].first]; j++){
			cout << v[i].first << " ";
		}
	}
}