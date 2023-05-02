#include <iostream>
#include <stack>
using namespace std;
bool o, c;
int main(){
	int cnt=0, res=0;
	stack<pair<char,int>>st;
	string s; cin >> s;
	for(int i=0; i<s.length(); i++){
		if(s[i]==')'){
			cnt=0;
			while(st.top().first!='('){
				cnt+=st.top().second;
				st.pop();
			}
			st.pop();
			cnt*=(st.top().first-'0');
			st.pop();
			st.push({'1',cnt});
		}
		else st.push({s[i],1});
	}
	while(!st.empty()){
		res+=st.top().second;
		st.pop();
	}
	cout << res;
}