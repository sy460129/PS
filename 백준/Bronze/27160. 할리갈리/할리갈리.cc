#include <iostream>
#include <map>
using namespace std;
map<string, int>m;
bool flag;
int main(){
	int n, x; cin >> n;
	string s;
	for(int i=0; i<n; i++){
		cin >> s >> x;
		m[s]+=x;
	}
	for(auto it=m.begin(); it!=m.end(); it++){
		if(it->second==5) flag=true;
	}
	flag ? cout << "YES" : cout << "NO";
}