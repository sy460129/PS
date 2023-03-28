#include<iostream>
#include<vector>
using namespace std;
int main() {
	string c;
	int a = 0;
	cin >> c;
	for (int i = 0; i < c.size(); i++) {
		a = i+1;
	}
	cout << a;
}