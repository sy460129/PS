#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	string s, x;
	cin >> s;
	while(--n){
		cin >> x;
		for(int i=0; i<s.length(); i++){
			if(s[i]!=x[i]){
				s[i]='?';
			}
		}
	}
	cout << s;
}