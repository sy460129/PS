#include <iostream>
using namespace std;
int main(){
	string s;
	int u=0, d=0;
	cin >> s;
	for(int i=0; i<s.length(); i++){
		if(s[i]=='U' || s[i]=='C') u++;
		else if(s[i]=='D' || s[i]=='P') d++;
	}
	if(u>(d+1)/2) cout << "U";
	if(d!=0) cout << "DP";
}