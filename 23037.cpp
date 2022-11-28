#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int ans=0;
	string s;
	cin >> s;
	for(int i=0; i<5; i++){
		int x=s[i]-'0';
		ans+=pow(x, 5);
	}
	cout << ans;
}