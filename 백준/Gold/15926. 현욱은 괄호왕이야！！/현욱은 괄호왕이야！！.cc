#include <iostream>
#include <stack>
using namespace std;
stack<int>s;
bool check[200001];
int main() {
	int n, ans=0, cnt=0;
	char c;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> c;
		if(c=='('){
			cnt++;
			s.push(i);
		}
		else{
			if(cnt!=0){
				cnt--;
				check[i]=true;
				check[s.top()]=true;
				s.pop();
			}
		}
	}
	cnt=0;
	for(int i=0; i<n; i++){
		if(check[i]){
			cnt++;
		}
		else{
			ans=max(cnt, ans);
			cnt=0;
		}
	}
	ans=max(cnt, ans);
	cout << ans;
}