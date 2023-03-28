#include <iostream>
#include <stack>
using namespace std;
stack<int>st;
int main(){
	int n, cnt=0; cin >> n;
	string s;
	while(n--){
		cin >> s;
		for(int i=0; i<s.length(); i++){
			if(st.empty()) st.push(s[i]);
			else if(st.top()==s[i]) st.pop();
			else st.push(s[i]);
		}
		if(st.empty()) cnt++;
		while(!st.empty()) st.pop();
	}
	cout << cnt;
}