#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
stack<string>st,st2;
vector<string>v;
int c=0;
bool cmp(string a, string b){
	if(a[0]==b[0]){
		if(a.length()!=b.length()){
			return a.length()<b.length();
		}
		else{
			return a<b;
		}
	}
	else{
		return a<b;
	}
}
int main(){
	int n,t=0;
	string s;
	cin >> n;
	for(int j=0; j<n*5; j++){
		cin >> s;
		v.push_back(s);
	}
	for(int j=n*5-1; j>=0; j--){
		st.push(v[j]);
	}
	sort(v.begin(), v.end(), cmp);
	while(1){
		if(!st.empty() && v[t]==st.top()){
			t++;
			st.pop();
		}
		else if(!st2.empty() && v[t]==st2.top()){
			t++;
			st2.pop();
		}
		else if(!st.empty() && v[t]!=st.top()){
			st2.push(st.top());
			st.pop();
		}
		else{
			break;
		}
	}
	if(st.empty() && st2.empty()){
		cout << "GOOD";
	}
	else{
		cout << "BAD";
	}
}