#include <iostream>
using namespace std;
int main(){
	int n, g=0, c=0, a=0, t=0, ans=10001;
	string s;
	cin >> n >> s;
	char ch;
	for(int i=0; i<n; i++){
		if(s[i]=='A') a++;
		else if(s[i]=='G') g++;
		else if(s[i]=='C') c++;
		else t++;
	}
	if(ans>a) ans=a, ch='A';
	if(ans>g) ans=g, ch='G';
	if(ans>c) ans=c, ch='C';
	if(ans>t) ans=t, ch='T';
	
	cout << ans << "\n";
	for(int i=0; i<n; i++) cout << ch;
}