#include <iostream>
#include <stack>
#include <cmath>
using namespace std;
int arr[31];
stack<int>st;
int main(){
	int a,b,n,res=0;
	cin >> a >> b >> n;
	for(int i=n-1;i>=0;i--){
		cin >> arr[i];
	}
	for(int i=0;i<n;i++){
		res+=pow(a,i)*arr[i];
	}
	while(res!=0){
		st.push(res%b);
		res/=b;
	}
	while(!st.empty()){
		cout << st.top() << " ";
		st.pop();
	}
}