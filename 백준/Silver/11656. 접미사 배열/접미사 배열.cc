#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
	vector<string>v;
	string s, c, t;
	cin >> s;
	reverse(s.begin(), s.end());
	for(int i=0; i<s.length(); i++){
		c+=s[i];
		t=c;
		reverse(c.begin(), c.end());
		v.push_back(c);
		c=t;
	}
	sort(v.begin(), v.end());
	for(auto&e : v){
		cout << e << "\n";
	}
}