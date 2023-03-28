#include <iostream>
using namespace std;
int main(){
	int n, x, y;
	string s;
	char c;
	cin >> n;
	while(n--){
		cin >> x >> y >> s;
		for(int i=0; i<s.length(); i++){
			c=(((s[i]-'A')*x + y)%26)+'A';
			cout << c;
		}
		cout << "\n";
	}
}