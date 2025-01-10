#include <iostream>
#include <stack>
using namespace std;
stack<int>s;
int main(){
	int n, a, b;
	cin >> n >> a >> b;
	if(a+b>n+1){
		cout << -1;
		return 0;
	}
	if(a>=b){
		for(int i=0; i<n-a-b+2; i++){
			cout << 1 << " ";
		}
		for(int i=2; i<=a; i++){
			cout << i << " ";
		}
		for(int i=b-1; i>0; i--){
			cout << i << " ";
		}
	}
	else{
		if(a==1){
			for(int i=1; i<b; i++){
				s.push(i);
			}
			for(int i=0; i<n-a-b+1; i++){
				s.push(1);
			}
			s.push(b);
		}
		else{
			for(int i=1; i<=b; i++){
				s.push(i);
			}
			for(int i=a-1; i>0; i--){
				s.push(i);
			}
			for(int i=0; i<n-a-b+1; i++){
				s.push(1);
			}
		}
		
		while(!s.empty()){
			cout << s.top() << " ";
			s.pop();
		}
	}
}