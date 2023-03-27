#include <iostream>
#include <map>
using namespace std;
string m2[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, k;
	string s, t;
	cin >> n >> k;
	map<string, int>m;
	for(int i=1; i<=n; i++){
		cin >> s;
		m[s]=i;
		m2[i]=s;
	}
	while(k--){
		cin >> t;
		t[0]>'0' && t[0]<='9' ? cout << m2[stoi(t)] << "\n" : cout << m[t] << "\n";
	}
}