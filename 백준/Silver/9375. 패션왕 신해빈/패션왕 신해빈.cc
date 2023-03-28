#include <iostream>
#include <map>
using namespace std;
map<string, int>m;
int n, t, cnt;
bool check[31];
int main(){
	cin >> t;
	string s, c;
	while(t--){
		cin >> n;
		cnt=1;
		for(int i=0; i<n; i++){
			cin >> s >> c;
			m[c]++;
		}
		for(auto e : m) cnt*=(e.second+1);
		m.clear();
		cout << cnt-1 << "\n";
	}
}