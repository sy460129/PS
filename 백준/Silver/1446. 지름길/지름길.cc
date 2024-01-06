#include <iostream>
#include <vector>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;
using t=tuple<int,int,int>;
int m[10001];
vector<t>v;
int main(){
	int n, k, a, b, c; cin >> n >> k;
	for(int i=1; i<=k; i++) m[i]=i;
	while(n--){
		cin >> a >> b >> c;
		if(a<b && c<b-a) v.push_back({b,a,c});
	}
	sort(v.begin(), v.end());
	for(int i=0; i<v.size(); i++){
		for(int j=1; j<=k; j++){
			if(get<0>(v[i])==j) m[j]=min(m[j], get<2>(v[i])+m[get<1>(v[i])]);
			else m[j]=min(m[j-1]+1, m[j]);
		}
	}
	cout << m[k];
}