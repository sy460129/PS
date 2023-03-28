#include <iostream>
using namespace std;
int main(){
	int cs=0, cu=0;
	string s; cin >> s;
	for(int i=0; i<s.length(); i++){
		if(s[i]==':') cs++;
		else if(s[i]=='_') cu++;
	}
	cout << s.length()+cs+cu*5;
}