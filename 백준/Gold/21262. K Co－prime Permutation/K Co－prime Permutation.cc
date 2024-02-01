#include <iostream>
#include <stack>
using namespace std;
stack<int>s;
int main(){
	int n, k; cin >> n >> k;
	if(!k){
		cout << -1;
		return 0;
	}
	for(int i=0; i<n-k; i++) s.push(n-i);
	for(int i=k; i>1; i-=2){
		s.push(i-1);
		s.push(i);
	}
	if(s.size()!=n) s.push(1);
	while(!s.empty()){
		cout << s.top();
		s.pop();
		if(!s.empty()) cout << " ";
	}
}