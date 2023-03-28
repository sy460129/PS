#include <iostream>
using namespace std;
int main(){
	int cnt = 0;
	string s;
	cin >> s;
	for(int i=0; i<s.length(); i++){
		if(s[i]=='c'){
			if(i+1<s.length() && (s[i+1]=='-' || s[i+1]=='=')){
				i++;
			}
			cnt++;
		}
		else if(s[i]=='d'){
			if(i+1<s.length() && s[i+1]=='-'){
				i++;
			}
			else if(i+1<s.length() && s[i+1]=='z'){
				if(i+2<s.length()&& s[i+2]=='='){
					i+=2;
				}
			}
			cnt++;
		}
		else if(s[i]=='l'){
			if(i+1<s.length() && s[i+1]=='j'){
				i++;
			}
			cnt++;
		}
		else if(s[i]=='n'){
			if(i+1<s.length() && s[i+1]=='j'){
				i++;
			}
			cnt++;
		}
		else if(s[i]=='s'){
			if(i+1<s.length() && s[i+1]=='='){
				i++;
			}
			cnt++;
		}
		else if(s[i]=='z'){
			if(i+1<s.length() && s[i+1]=='='){
				i++;
			}
			cnt++;
		}
		else{
			cnt++;
		}
	}
	cout << cnt;
}