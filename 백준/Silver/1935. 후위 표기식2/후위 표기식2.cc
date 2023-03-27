#include <iostream>
#include <stack>
#include <iomanip>
using namespace std;
double arr[26];
stack<double>st;
int main(){
	int n; cin >> n;
	double x, y;
	string s; cin >> s;
	for(int i=0; i<n; i++) cin >> arr[i];
	for(int i=0; i<s.length(); i++){
		if(s[i]>='A' && s[i]<='Z') st.push(arr[s[i]-'A']);
		else{
			x=st.top(); st.pop();
			y=st.top(); st.pop();
			if(s[i]=='+') st.push(x+y);
			else if(s[i]=='*') st.push(x*y);
			else if(s[i]=='/') st.push(y/x);
			else if(s[i]=='-') st.push(y-x);
		}
	}
	cout << fixed << setprecision(2) << st.top();
}