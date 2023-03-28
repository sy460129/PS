#include <iostream>
#include <set>
using namespace std;
char arr[1001];
int main(){
	set<string>s;
	string c, t;
	cin >> c;
	for(int i=0; i<c.length(); i++){
		arr[i]=c[i];
	}
	for(int i=0; i<c.length(); i++){
		for(int j=i; j<c.length(); j++){
			t+=arr[j];
			s.insert(t);
		}
		t="";
	}
	cout << s.size();
}