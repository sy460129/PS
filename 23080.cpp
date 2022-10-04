#include <iostream>
using namespace std;
int main() {
	int n;
	string s, c;
	cin >> n >> s;
	for(int i=0; i<s.length(); i++){
		if(i%n==0){
			c+=s[i];
		}
	}
	cout << c;
}