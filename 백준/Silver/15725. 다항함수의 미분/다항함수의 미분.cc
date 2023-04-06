#include <iostream>
using namespace std;
bool t;
int main(){
	string s,c;
	cin >> s;
	if(s[0]=='x'){
		cout << 1;
	}
	else if(s[0]=='-'){
		if(s[1]=='x'){
			cout << -1;
		}
		else{
			for(int i=1; i<s.length(); i++){
				if(s[i]!='x'){
					c+=s[i];
				}
				else{
					if(s[i]=='x')
					t=true;
					break;
				}
			}
			if(t){
				cout << "-" << c;
			}
			else{
				cout << 0;
			}
		}
	}
	else{
		for(int i=0; i<s.length(); i++){
			if(s[i]!='x'){
				c+=s[i];
			}
			else{
				if(s[i]=='x'){
					t=true;
				}
				break;
			}
		}
		if(t){
			cout << c;
		}
		else{
			cout << 0;
		}
	}
}