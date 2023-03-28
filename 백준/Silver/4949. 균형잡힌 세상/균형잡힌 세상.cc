#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main() {
	string s;
	while (1) {
		stack<char>st;
		getline(cin, s);
		if (s[0] == '.') {
			return 0;
		}
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
				st.push(s[i]);
			}
			if (s[i] == ')') {
				if (!st.empty() && st.top() == '(') {
					st.pop();
				}
				else {
					st.push(s[i]);
				}
			}
			if (s[i] == '}') {
				if (!st.empty() && st.top() == '{') {
					st.pop();
				}
				else {
					st.push(s[i]);
				}
			}
			if (s[i] == ']') {
				if (!st.empty() && st.top() == '[') {
					st.pop();
				}
				else {
					st.push(s[i]);
				}
			}
		}
		if (st.empty()) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
	}
}