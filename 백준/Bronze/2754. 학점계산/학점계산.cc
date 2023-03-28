#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(){
	double a;
	string s;
	cin >> s;
	if(s[0]=='A'){
		if(s[1]=='+'){
			a=4.3;
		}
		else if(s[1]=='0'){
			a=4.0;
		}
		else{
			a=3.7;
		}
	}
	else if(s[0]=='B'){
		if(s[1]=='+'){
			a=3.3;
		}
		else if(s[1]=='0'){
			a=3.0;
		}
		else{
			a=2.7;
		}
	}
	else if(s[0]=='C'){
		if(s[1]=='+'){
			a=2.3;
		}
		else if(s[1]=='0'){
			a=2.0;
		}
		else{
			a=1.7;
		}
	}
	else if(s[0]=='D'){
		if(s[1]=='+'){
			a=1.3;
		}
		else if(s[1]=='0'){
			a=1.0;
		}
		else{
			a=0.7;
		}
	}
	else{
		a=0.0;
	}
	cout << fixed <<setprecision(1) << a;
}