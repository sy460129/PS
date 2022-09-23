#include <iostream>
#include <vector>
using namespace std;
vector<int>v(3);
int main() {
	int n, ans=0;
	cin >> n;
	if(n%2==0){
		for(int i=0; i<n; i++) i%2==0 ? cout << 1 << " " : cout << 2 << " ";
	}
	else{
		for(int i=0; i<n-1; i++) i%2==0 ? cout << 1 << " " : cout << 2 << " ";
		cout << 3;
	}
}