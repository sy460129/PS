#include <iostream>
using namespace std;
int main(){
	bool c;
	int n; cin >> n >> c;
	if(!c && n>=12 && n<=16) cout << 320;
	else cout << 280;
}