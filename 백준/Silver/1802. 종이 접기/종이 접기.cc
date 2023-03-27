#include <iostream>
using namespace std;
bool check;
void str(string c){
	if(c.length()==1) return;
	string a, b;
	for(int i=0; i<c.length()/2; i++){
		if(c[i]==c[c.length()-i-1]) check=false;
		a+=c[i], b+=c[c.length()-i-1];
	}
	if(check) str(a);
	if(check) str(b);
}
int main(){
	string s;
	int n; cin >> n;
	while(n--){
		check=true;
		cin >> s;
		str(s);
		check ? cout << "YES\n" : cout << "NO\n";
	}
}