#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	string s, x;
	cin >> s;
	for(int i=0; i<s.length(); i++){
		if(s[i]=='P'){
			x+='r';
		}
		else if(s[i]=='E'){
			x+="ye";
		}
		else if(s[i]=='B'){
			x+='v';
		}
		else if(s[i]=='H'){
			x+='n';
		}
		else if(s[i]=='C'){
			x+='s';
		}
		else if(s[i]=='Y'){
			x+='u';
		}
		else if(s[i]=='X'){
			x+='h';
		}
		else{
			x+=tolower(s[i]);
		}
	}
	cout << x;
}