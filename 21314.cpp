#include <iostream>
#include <stack>
using namespace std;
stack<char>st;
int main() {
	string s, c, m;
	cin >> s;
	for(int i=0; i<s.length(); i++){
		if(s[i]=='M'){
			st.push('M');
		}
		else{
			c+='5';
			while(!st.empty()){
				c+='0';
				st.pop();
			}
		}
	}
	while(!st.empty()){
		c+='1';
		st.pop();
	}
	for(int i=0; i<s.length(); i++){
		if(s[i]=='M'){
			st.push('M');
		}
		else{
			if(!st.empty()){
				m+='1';
				st.pop();
			}
			while(!st.empty()){
				m+='0';
				st.pop();
			}
			m+='5';
		}
	}
	if(!st.empty()){
		m+='1';
		st.pop();
		while(!st.empty()){
			m+='0';
			st.pop();
		}
	}
	cout << c << "\n" << m;
}