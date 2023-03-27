#include <iostream>
using namespace std;
int main() {
	string s, x;
	for(int i=0; i<2; i++){
		cin >> s;
		if(s=="black" && i==1 && x!="0"){
			x+="0";
		}
		else if(s=="brown"){
			x+='1';
		}
		else if(s=="red"){
			x+='2';
		}
		else if(s=="orange"){
			x+='3';
		}
		else if(s=="yellow"){
			x+='4';
		}
		else if(s=="green"){
			x+='5';
		}
		else if(s=="blue"){
			x+='6';
		}
		else if(s=="violet"){
			x+='7';
		}
		else if(s=="grey"){
			x+='8';
		}
		else if(s=="white"){
			x+='9';
		}
	}
	cin >> s;
	if(x=="0"){
		cout << x;
		return 0;
	}
	if(s=="brown"){
		x+="0";
	}
	else if(s=="red"){
		x+="00";
	}
	else if(s=="orange"){
		x+="000";
	}
	else if(s=="yellow"){
		x+="0000";
	}
	else if(s=="green"){
		x+="00000";
	}
	else if(s=="blue"){
		x+="000000";
	}
	else if(s=="violet"){
		x+="0000000";
	}
	else if(s=="grey"){
		x+="00000000";
	}
	else if(s=="white"){
		x+="000000000";
	}
	cout << x;
}