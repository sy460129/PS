#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	string s, c, ans;
	cin >> s;
	ans=s;
	for(int i=0; i<s.length()-2; i++){
		for(int j=i+1; j<s.length()-1; j++){
			c=s;
			reverse(c.begin(), c.begin()+i+1);
			reverse(c.begin()+i+1, c.begin()+j+1);
			reverse(c.begin()+j+1, c.end());
			ans=min(ans,c);
			if(ans==s){
				ans=c;
			}
		}
	}
	cout << ans;
}