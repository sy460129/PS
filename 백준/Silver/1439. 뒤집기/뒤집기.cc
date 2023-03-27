#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	vector<char>v;
	string s;
	cin >> s;
	for(int i=0; i<s.length(); i++){
		v.push_back(s[i]);
	}
	v.erase(unique(v.begin(), v.end()), v.end());
	cout << v.size()/2;
}