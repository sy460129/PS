#include <iostream>
#include <stack>
#include <iomanip>
using namespace std;
double arr[26];
stack<double>st;
int main() {
	double n, ans, x, y;
	string s;
	cin >> n >> s;
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	for(int i=0; i<s.length(); i++){
		if(s[i]>='A' && s[i]<='Z'){
			st.push(arr[s[i]-'A']);
		}
		else{
			ans=0;
			x=st.top();
			st.pop();
			y=st.top();
			st.pop();
			if(s[i]=='+'){
				ans+=x+y;
			}
			else if(s[i]=='-'){
				ans+=y-x;
			}
			else if(s[i]=='/'){
				ans+=y/x;
			}
			else if(s[i]=='*'){
				ans+=x*y;
			}
			st.push(ans);
		}
	}
	cout << fixed << setprecision(2) << st.top();
}