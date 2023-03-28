#include <iostream>
#include <deque>
using namespace std;
deque<int>st;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	string s;
	int n, x; cin >> n;
	while(n--){
		cin >> s;
		if(s=="push_front"){
			cin >> x;
			st.push_front(x);
		}
		else if(s=="push_back"){
			cin >> x;
			st.push_back(x);
		}
		else if(s=="front"){
			if(!st.empty()) cout << st.front() << "\n";
			else cout << -1 << "\n";
		}
		else if(s=="back"){
			if(!st.empty()) cout << st.back() << "\n";
			else cout << -1 << "\n";
		}
		else if(s=="pop_front"){
			if(!st.empty()){
				cout << st.front() << "\n";
				st.pop_front();
			}
			else cout << -1 << "\n";
		}
		else if(s=="pop_back"){
			if(!st.empty()){
				cout << st.back() << "\n";
				st.pop_back();
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