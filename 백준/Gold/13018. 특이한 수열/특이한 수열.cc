#include <iostream>
#include <stack>
using namespace std;
int main(){
	int n, k; cin >> n >> k;
	stack<int>s;
	for(int i=n; i>n-k; i--) s.push(i);
	for(int i=n-k; i>1; i-=2){
		s.push(i-1);
		s.push(i);
	}
	if(n==k){
		cout << "Impossible";
		return 0;
	}
	if(s.size()!=n) s.push(1);
	while(!s.empty()){
		cout << s.top() << " ";
		s.pop();
	}
}