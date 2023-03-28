#include <iostream>
#include <stack>
using namespace std;
stack<int>st[80001], s;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, x;
	char c;
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> c;
		st[i]=s;
		if(c=='a'){
			cin >> x;
			st[i].push(x);
			s.push(x);
			cout << x << "\n";
		}
		else if(c=='s'){
			if(!st[i].empty()){
				st[i].pop();
			}
			if(!st[i].empty()){
				cout << st[i].top() << "\n";
			}
			else{
				cout << -1 << "\n";
			}
			s=st[i];
		}
		else if(c=='t'){
			cin >> x;
			st[i]=st[x-1];
			if(!st[i].empty()){
				cout << st[i].top() << "\n";
			}
			else{
				cout << -1 << "\n";
			}
			s=st[i];
		}
	}
}