#include <iostream>
using namespace std;
bool c;
int main(){
	int n, x, i=1; cin >> n;
	string s;
	while(n--){
		cin >> s >> x;
		if(s=="HOURGLASS" && x==i) cout << i << " NO\n";
		else if(s=="HOURGLASS") {
			cout << i << " NO\n";
			c=!c;
		}
		else if(x==i) cout << i << " YES\n";
		else cout << i << " NO\n";
		!c ? i++ : i--;
		if(i>12) i=1;
		if(i<1) i=12;
	}
}