#include <iostream>
using namespace std;
int main() {
	int x;
	string s;
	cin >> x;
	while(x--){
		cin >> s;
		cout << s[0] << s[s.length()-1] << "\n";
	}
}