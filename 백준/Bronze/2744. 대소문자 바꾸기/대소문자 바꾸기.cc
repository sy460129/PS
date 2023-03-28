#include <iostream>
using namespace std;
int main() {
	string s;
	cin >> s;
	for(int i=0; i<s.length(); i++){
		if(towupper(s[i])==s[i]){
			s[i]=towlower(s[i]);
		}
		else{
			s[i]=towupper(s[i]);
		}
	}
	cout << s;
}