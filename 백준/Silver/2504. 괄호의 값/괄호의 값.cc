#include <iostream>
#include <stack>
using namespace std;
int main(){
	stack<char>st;
	stack<int>st2;
	string s; cin >> s;
	int cnt=1, ans=0;
	for(int i=0; i<s.length(); i++){
		if(s[i]=='('){
			cnt*=2;
			st.push(s[i]);
		}
		else if(s[i]=='['){
			cnt*=3;
			st.push(s[i]);
		}
		else if(s[i]==')'){
			if(st.empty() || st.top()!='('){
				cout << 0;
				return 0;
			}
			else{
				if(s[i-1]=='(') ans+=cnt;
				st.pop();
				cnt/=2;
			}
		}
		else if(s[i]==']'){
			if(st.empty() || st.top()!='['){
				cout << 0;
				return 0;
			}
			else{
				if(s[i-1]=='[') ans+=cnt;
				st.pop();
				cnt/=3;
			}
		}
		else{
			cout << 0;
			return 0;
		}
	}
	if(!st.empty()) cout << 0;
	else cout << ans;
}