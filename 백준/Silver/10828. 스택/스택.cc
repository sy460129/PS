#include <iostream>
#include <stack>
using namespace std;
stack<int>st;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s;
	int n, x; cin >> n;
	while(n--){
		cin >> s;
		if(s=="push"){
			cin >> x;
			st.push(x);
		}
		else if(s=="top"){
			if(!st.empty()) cout << st.top() << "\n";
			else cout << -1 << "\n";
		}
		else if(s=="pop"){
			if(!st.empty()){
				cout << st.top() << "\n";
				st.pop();
			}
			else cout << -1 << "\n";
		}
		else if(s=="size"){
			cout << st.size() << "\n";
		}
		else if(s=="empty"){
			st.empty() ? cout << 1 << "\n" : cout << 0 << "\n";
		}
	}
}