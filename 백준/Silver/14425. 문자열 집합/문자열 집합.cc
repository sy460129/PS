#include <iostream>
#include <map>
using namespace std;
int main(){
	map<string ,int> m;
	int a, b, ans=0;
	string s;
	cin >> a >> b;
	while(a--){
		cin >> s;
		m[s]=1;
	}
	while(b--){
		cin >> s;
		if(m[s]==1) ans++;
	}
	cout << ans;
}